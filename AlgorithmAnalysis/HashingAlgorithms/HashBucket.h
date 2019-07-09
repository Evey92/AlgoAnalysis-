#pragma once

template<typename K, typename V>
class HashBucketItem
{
 public:

   HashBucketItem(const K &key, const V &value)
   : m_key(key), m_value(value), m_next(nullptr) {}
   ~HashBucketItem() = default;
   

   //************************************
   // Method:    getKey
   // FullName:  HashBucketItem<K, V>::getKey
   // Access:    public 
   // Returns:   K
   // Qualifier: const
   //************************************
   K 
   getKey() const
   {
     return m_key;
   }

   //************************************
   // Method:    getValue
   // FullName:  HashBucketItem<K, V>::getValue
   // Access:    public 
   // Returns:   V
   // Qualifier: const
   //************************************
   V 
   getValue() const
   {
     return m_value;
   }

   //************************************
   // Method:    setValue
   // FullName:  HashBucketItem<K, V>::setValue
   // Access:    public 
   // Returns:   void
   // Qualifier:
   // Parameter: V value
   //************************************
   void
   setValue(V value)
   {
     m_value = value;
   }
   
   //************************************
   // Method:    getNode
   // FullName:  HashBucketItem<K, V>::getNode
   // Access:    public 
   // Returns:   HashBucketItem*
   // Qualifier: const
   //************************************
   HashBucketItem*
   getNext() const
   {
     return m_next;
   }

   //************************************
   // Method:    setNext
   // FullName:  HashBucketItem<K, V>::setNext
   // Access:    public 
   // Returns:   void
   // Qualifier:
   // Parameter: HashBucketItem * next
   //************************************
   void
   setNext(HashBucketItem* next)
   {
     m_next = next;
   }
 

 private:
   K m_key;
   V m_value;
   HashBucketItem* m_next;
};

