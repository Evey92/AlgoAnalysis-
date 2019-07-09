#pragma once
#include <vector>
#include <functional>
#include "HashBucket.h"


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
   setHashFunction(int(*func)(int key, int tableSize)) {
     hasFunc = func;
   }

  bool
  get(const K &key, V &value) {

    int hashIndex = hasFunc(key);
    HashBucketItem<K, V>* entry = m_table[hashIndex];
    
    while (entry != nullptr)
    {
      if (entry->getKey() == key)
      {
        value = entry->getValue();
        return true;
      }

      entry = entry->getNext();
    }

    return false;
  }

  void
  put(const K &key, const V &value) {
    
    int hashIndex = hasFunc(key);
    HashBucketItem<K, V>* prev = nullptr;
    HashBucketItem<K, V>* entry = m_table[hashIndex];

    while (entry != nullptr && entry->getKey() != key)
    {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == nullptr)
    {
      entry = new HashBucketItem<K, V>(key, value);
      
      if (prev == nullptr)
      {
        m_table[hashIndex] = entry;
      }
      else
      {
        prev->setNext(entry);
      }
    }
    else
    {
      entry->setNext(value);
    }
  }

  void
  put(const K &key) {

    int hashIndex = hasFunc(key, tableSize);
    HashBucketItem<K, V>* prev = nullptr;
    HashBucketItem<K, V>* entry = m_table[hashIndex];

    while (entry != nullptr)
    {
      prev = entry;
      entry = entry->getNext();
    }

    entry = new HashBucketItem<K, V>(hashIndex, key);

    if (prev == nullptr)
    {
      m_table[hashIndex] = entry;
    }
    else
    {
      prev->setNext(entry);
    }
  }

  void
  remove(const K &key) {

    int hashIndex = hasFunc(key);
    HashBucketItem<K, V>* prev = nullptr;
    HashBucketItem<K, V>* entry = m_table[hashIndex];

    while (entry != nullptr && entry->getKey() != key)
    {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == nullptr)
    {
      std::cout << "Couldn't find key: " << key << "\n";
      return;
    }
    else
    {
      if (prev == nullptr) //this is the first element in the bucket
      {
        m_table[hashIndex] = entry->getNext();
      }
      else
      {
        prev->setNext(entry->getNext());
      }

      delete entry;
    }
  }

  void
  showTable()
  {
    HashBucketItem<K, V>* prev = nullptr;
    int buckets[tableSize];
    int count = 0;
    int totalItems = 0;

    for (int i = 0; i < tableSize; ++i)
    {
      HashBucketItem<K, V>* entry = m_table[i];
      HashBucketItem<K, V>* prev = nullptr;

      while (entry != nullptr)
      {
        prev = entry;
        entry = entry->getNext();
        ++count;
      }

      buckets[i] = count;
      totalItems += count;
      count = 0;
    }

    for (int i = 0; i < tableSize; ++i)
    {
      std::cout << "Items in bucket: " << i << ": " << buckets[i] << "\n";
    }

    std::cout << "Total items: " << totalItems << "\n";


  }

 private:
   HashBucketItem<K, V>* m_table[tableSize];
   int(*hasFunc)(int key, int tableSize);
};
