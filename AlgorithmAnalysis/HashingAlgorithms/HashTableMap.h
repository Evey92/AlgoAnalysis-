#pragma once
#include <vector>
#include <functional>
#include "HashBucket.h"
struct HashFunctions {
  //Insert hash functions here
};

template<typename K, typename V, size_t  tableSize>
class HashTableMap
{
 public:
   HashTableMap() = default;
   ~HashTableMap() {
     for (size_t i = 0; i < tableSize;)
     {
       HashBucketItem<K, V>* entry = m_table[i];
       while (entry != nullptr)
       {
         HashBucketItem<K, V>* prev = entry;
         entry = entry->getNext();
         delete prev;
       }
       m_table[i] = nullptr;
     }
   }

  void 
  setHashFunction(std::function<UINT32(K)> func) {
    hasFunc = &func;
  }

  bool
  get(const K &key, V &value){
    UINT32 hashIndex = hasFunc(key);
    HashBucketItem<K, V>* entry = m_table[hashIndex];
    while (entry != nullptr)
    {
      if (entry->getKey() == key)
      {
        value = entry->getValue();
      }
    }
  }

 private:
   HashBucketItem<K, V>* m_table[tableSize];
   UINT32(*hasFunc)(K key);
};

