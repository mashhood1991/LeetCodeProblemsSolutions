//Node class for getting node next & prev pointer and also to initialize key, val
//we would need a node , so let's write a node class befor going to LRUCache class
class Node{
    
public: //we would need next & prev pointer access so either decalre Node as structure class or make the member variable as public 
    //each node will have a key, value pair
    //we also need two pointers, one for the previous node and one for the next node

    int key, val;
    Node* next, *prev;
    
    //constructor to initilize the key, value and the pointers
    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = prev = nullptr; //both can initianlly be set to NULL
    }
};


class LRUCache {
    
private: //declare member variables as private
    //capacity needs to be stored because we want to know if we go over the capacity
    int capacity;
    //we also need a hashmap which maps the key to Node. key will be of int type and mapped value will be of Node pointer type
    unordered_map<int, Node*> cache;    
    Node* head, *tail; 
    
public:
    //Initialize the LRUCache with positive size capacity
    //LRUCache object will be instantiated
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        //before we have any value into the cache, we want dummy pointers or nodes which tells us where are the most recent or least recent values we have added
        //head will help us to find most recently used and tail will help us to find least recently used (LRU)
        this->head = new Node(-1 , -1); //it stores the location of most recent. default key and value is -1
        this->tail = new Node(-1 , -1); //it stores the location of least recent. default key and value is -1
        
        //Initially, we want the above two nodes (head and tail) to be connected to each other, because if we want to put a node, we will put it in the middle(between head and tail)
        head->next = tail; //next of head is tail
        tail->prev = head; //prev of tail is head        
    }
    
    
    //helper functions
    //everytime we get a value, we want to update it to most recent one, let's write remove and insert helper function for that; these helper function will be applied to our linked list
    //insert node at right  
    void addNode(Node* newNode) {
        Node* hnext = head->next;
        
        newNode->next = hnext;
        head->next = newNode;
        
        newNode->prev = head;
        hnext->prev = newNode;
    }    
    //remove node from list
    void deleteNode(Node* delNode) {
        Node* delNodeNext = delNode->next;
        Node* delNodePrev = delNode->prev;
        
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;
    }
    
    
    //Return the value of the key if the key exists, otherwise return -1
    int get(int key) {
        //if the key is in our cache, we can return the value
        if(cache.find(key) != cache.end()) { //if key is present
            Node* preNode = cache[key]; // pick the node
            int preVal = preNode->val; // store its val
            deleteNode(preNode); // delete it (just change the links)
            addNode(preNode); // add it to front (use the previously created node)
            return preVal; // return stored val
        }
        return -1;    
    }
    
    
    // Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key
    void put(int key, int value) {
        //if the key is in our cache, we update the value of the key
        if(cache.find(key) != cache.end()) { // if key is present
            Node* existingNode = cache[key]; // pick the node
            existingNode->val = value; // change its value
            deleteNode(existingNode); // delete it
            addNode(existingNode); // add it to the front
        } else {
            if(cache.size() == capacity) {
                Node* lru = tail->prev; // pick least recently used node (node present before tail) 
                cache.erase(lru->key); // erase from map
                deleteNode(lru); // delete it (just change links)
                delete(lru); // delete it permanently
            }
            Node* temp = new Node(key,value); // create new node
            cache[key] = temp; // add it to map
            addNode(temp); // add it to the front
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
