/*
1) Pair:
Decleration and Intialization:
    pair<data type1, data type2> pairName = {value1, value2};
    pair<data type1, data type2> pairName = make_pair(value1, value2);

Accessing Values:
    pairName.first   // returns first value
    pairName.second  // returns second value
*/

/*
2) Vector:
Declaration and Intailization:
    vector<data type> vectorName(size,value)    -> Declaration with specific size and Intializing all indexes with the givin value

Accessing Values:
    vectorName[index]   -> return value at the givin index

Methods and Time complexity:
    .push_back()/.emplace_back() : O(1)
    .pop_back() : O(1)
    .size() : O(1)
    .empty() : O(1)
    .front(): O(1)
    .back(): O(1)
    operator[]: O(1)
    .clear() : O(N)
    .resize(newSize) : O(N)
    
    .insert(position, value)  
        -> Insert value at given position  
        -> Example: v.insert(v.begin()+2, 50)  
        -> Time: O(N)

    .insert(position, count, value)  
        -> Insert "count" copies of value  
        -> Example: v.insert(v.begin(), 3, 7)  
        -> Time: O(N)

    .insert(position, firstIt, lastIt)  
        -> Insert range [firstIt, lastIt)  
        -> Example: v.insert(v.end(), v2.begin(), v2.end())  
        -> Time: O(N)

    .erase(position)  
        -> Remove element at given position  
        -> Example: v.erase(v.begin()+1)  
        -> Time: O(N)

    .erase(startPos, endPos)  
        -> Remove range [startPos, endPos)  
        -> Example: v.erase(v.begin(), v.begin()+3)  
        -> Time: O(N)
*/

/*
3) Stack:
Declaration:
    stack<data type> stackName;

Methods and Time complexity:
    .push() : O(1)
    .pop() : O(1)
    .top() : O(1)
    .size() : O(1)
    .empty() : O(1)
*/

/*
4) Queue:
Declaration:
    queue<data type> queueName;

Methods and Time complexity:
    .push() : O(1)
    .pop() : O(1)
    .front() : O(1)
    .back() : O(1)
    .size() : O(1)
    .empty() : O(1)
*/

/*
5) Priority Queue:
Declaration:
    priority_queue<data type> pq;
        -> By default: MAX-HEAP (largest element at top)

    priority_queue<data type, vector<data type>, greater<data type>> pq;
        -> MIN-HEAP (smallest element at top)

Basic Operations:
    pq.push(value)   -> Insert element
    pq.pop()         -> Remove top element
    pq.top()         -> Access top element
    pq.size()        -> Number of elements
    pq.empty()       -> Check if empty

Time Complexity:
    .push() : O(log N)
    .pop()  : O(log N)
    .top()  : O(1)
    .size() : O(1)
    .empty(): O(1)

Custom Comparator using lambda:

auto cmp = [](int a, int b) {
    return a > b;
};

Declaration:
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

Notes:
    - decltype(cmp) refers to the lambda's hidden type
    - Comparator object MUST be passed to constructor
*/
