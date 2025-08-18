#ifndef OPEN_ADDRESSING_H
#define OPEN_ADDRESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

// 해시 테이블의 각 슬롯(버킷)이 비어 있는지 / 사용 중인지 상태를 표시
enum ElementStatus
{
    EMPTY = 0, // 슬롯이 비어 있음
    OCCUPIED = 1 // 슬롯에 값이 들어 있음
};

// 해시 테이블의 **한 칸(슬롯, 버킷)**을 표현하는 구조체
typedef struct tagElementType
{
    KeyType    Key; // 데이터의 키 (검색/저장 기준이 되는 값)
    ValueType  Value; // 키와 연결된 실제 데이터
    enum ElementStatus Status; // 현재 슬롯이 비었는지, 채워졌는지
} ElementType;

// 해시 테이블 전체를 표현하는 구조체
typedef struct tagHashTable
{
    int           OccupiedCount; // 현재 몇 개의 슬롯이 사용 중인지 기록
    int           TableSize; // 테이블 전체 크기
    ElementType* Table; // 구조체 배열 → 슬롯들을 모아둔 배열
} HashTable;

HashTable* OAHT_CreateHashTable(int TableSize);
void       OAHT_DestroyHashTable(HashTable* HT);
void       OAHT_ClearElement(ElementType* Element);

void       OAHT_Set(HashTable** HT, KeyType Key, ValueType Value);
ValueType  OAHT_Get(HashTable* HT, KeyType Key);
int        OAHT_Hash(KeyType Key, int KeyLength, int TableSize);
int        OAHT_Hash2(KeyType Key, int KeyLength, int TableSize);

void       OAHT_Rehash(HashTable** HT);

#endif