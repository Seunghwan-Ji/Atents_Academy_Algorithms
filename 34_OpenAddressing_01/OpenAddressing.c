#define _CRT_SECURE_NO_WARNINGS
#include "OpenAddressing.h"

HashTable* OAHT_CreateHashTable(int TableSize)
{
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->Table = (ElementType*)malloc(sizeof(ElementType) * TableSize);

    memset(HT->Table, 0, sizeof(ElementType) * TableSize);

    HT->TableSize = TableSize;
    HT->OccupiedCount = 0;

    return HT;
}

void OAHT_Set(HashTable** HT, KeyType Key, ValueType Value)
{
    int    KeyLen, Address, StepSize;
    double Usage;

    // 해시 테이블의 점유율 = 채워진 슬롯 수 / 전체 슬롯 수
    Usage = (double)(*HT)->OccupiedCount / (*HT)->TableSize;

    // 점유율이 50% 초과하면 OAHT_Rehash()를 호출해서 테이블 크기를 늘리고 다시 해시.
    if (Usage > 0.5)
    {
        OAHT_Rehash(HT);
    }

    // 기본 해시값 & 보조 해시값 계산

    KeyLen = strlen(Key);

    // 기본 해시 함수로 나온 슬롯 인덱스
    Address = OAHT_Hash(Key, KeyLen, (*HT)->TableSize);

    // 보조 해시 함수 값 (이중 해싱에서 충돌 시 이동할 간격 역할)
    StepSize = OAHT_Hash2(Key, KeyLen, (*HT)->TableSize);

    // 충돌 해결 (이중 해싱)
    // 현재 테이블의 Address 슬롯이 비어있지 않고, 해당 슬롯의 키와 삽입할 키가 같지 않으면 반복.
    while ((*HT)->Table[Address].Status != EMPTY &&
        strcmp((*HT)->Table[Address].Key, Key) != 0) // strcmp(a, b): 문자열 a와 b를 비교, 같으면 0 반환
    {
        printf("Collision occured! : Key(%s), Address(%d), StepSize(%d)\n",
            Key, Address, StepSize);

        Address = (Address + StepSize) % (*HT)->TableSize;
        
        // 즉, 같은 키면 덮어쓰고, 다른 키면 StepSize 간격으로 탐색 → 이중 해싱(Double Hashing) 기법
    }

    (*HT)->Table[Address].Key = (char*)malloc(sizeof(char) * (KeyLen + 1));
    strcpy((*HT)->Table[Address].Key, Key);

    (*HT)->Table[Address].Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
    strcpy((*HT)->Table[Address].Value, Value);

    (*HT)->Table[Address].Status = OCCUPIED;

    (*HT)->OccupiedCount++;

    printf("Key(%s) entered at address(%d)\n", Key, Address);
}

ValueType OAHT_Get(HashTable* HT, KeyType Key)
{
    int KeyLen = strlen(Key);

    int Address = OAHT_Hash(Key, KeyLen, HT->TableSize);
    int StepSize = OAHT_Hash2(Key, KeyLen, HT->TableSize);

    while (HT->Table[Address].Status != EMPTY &&
        strcmp(HT->Table[Address].Key, Key) != 0)
    {
        Address = (Address + StepSize) % HT->TableSize;
    }

    return HT->Table[Address].Value;
}

void OAHT_ClearElement(ElementType* Element)
{
    if (Element->Status == EMPTY)
        return;

    free(Element->Key);
    free(Element->Value);
}

void OAHT_DestroyHashTable(HashTable* HT)
{
    //  1. 각 링크드 리스트를 자유 저장소에서 제거하기 
    int i = 0;
    for (i = 0; i < HT->TableSize; i++)
    {
        OAHT_ClearElement(&(HT->Table[i]));
    }

    //  2, 해시 테이블을 자유 저장소에서 제거하기
    free(HT->Table);
    free(HT);
}

int OAHT_Hash(KeyType Key, int KeyLength, int TableSize)
{
    int i = 0;
    int HashValue = 0;

    for (i = 0; i < KeyLength; i++)
    {
        HashValue = (HashValue << 3) + Key[i];
    }

    HashValue = HashValue % TableSize;

    return HashValue;
}

int OAHT_Hash2(KeyType Key, int KeyLength, int TableSize)
{
    int i = 0;
    int HashValue = 0;

    for (i = 0; i < KeyLength; i++)
    {
        HashValue = (HashValue << 2) + Key[i];
    }

    HashValue = HashValue % (TableSize - 3);

    return HashValue + 1;
}

void OAHT_Rehash(HashTable** HT)
{
    int i = 0;
    ElementType* OldTable = (*HT)->Table;

    //  새 해시 테이블을 만들고, 
    HashTable* NewHT = OAHT_CreateHashTable((*HT)->TableSize * 2);

    printf("\nRehashed. New table size is : %d\n\n", NewHT->TableSize);

    //  이전의 해시테이블에 있던 데이터를 새 해시테이블로 옮긴다. 
    for (i = 0; i < (*HT)->TableSize; i++)
    {
        if (OldTable[i].Status == OCCUPIED)
        {
            OAHT_Set(&NewHT, OldTable[i].Key, OldTable[i].Value);
        }
    }

    //  이전의 해시테이블은 소멸시킨다. 
    OAHT_DestroyHashTable((*HT));

    //  HT 포인터에는 새로 해시테이블의 주소를 대입한다. 
    (*HT) = NewHT;
}