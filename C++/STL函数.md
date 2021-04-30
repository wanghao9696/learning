

## string
```
int pos = str1.find(str2); // 查找
int pos = str1.rfind(str2); // 反向查找
str1.replace(1, 3, str2); // 替换
int ret = str1.compare(str2); // 比较

str.at(i) // 等价于str[i]
str.insert(3, str2); // 插入
str.earse(1, 3); // 删除
string str2 = str1.substr(1, 3); // 截取子串
```

## vector
> **单端数组**
```
v.empty(); // 判读是否为空
v.capacity(); // 返回容器容量 0 1 2 4 4 8 8 8 8 16 ...
v.size(); // 返回容器元素个数
v.resize(num, elem); // 重新指定容器

v.push_back(i);
v.pop_back(i);
v.insert(v.begin()+2, 2, 8); // 第三个位置开始插入2个8
v.erase(v.begin(), v.begin()+2); // 删除前两个元素
v.clear(); // 等价于v.erase(v.begin(), v.end())

v.front();
v.back();

v1.swap(v2); // 互换容器，可通过 vector<int>(v).swap(v) 来收缩内存
v.reserve(1000); // 预留空间

sort(d.begin()+2, d.end()); // 对第3到最后个元素排序
```

## deque
> **双端数组**
```
d.empty();
d.size();
d.resize(num, elem);

d.push_back(i);
d.push_front(i);
d.pop_back();
d.pop_front();

d.insert(d.begin(), elem);
d.insert(d.begin(), num, elem);
d1.insert(d1.begin(), d2.begin(), d2.end());
d.erase(d.begin(), d.begin()+2);
d.clear();

d.front();
d.back();

sort(d.begin()+2, d.end());
```

## stack
> **栈**，先进后出，只有一个出口，不允许遍历
```
stk.empty();
stk.size();

stk.push(i); // 栈顶添加元素
stk.pop(); // 栈顶移除元素

stk.top(); // 返回栈顶的元素
```

## queue
> **队列**，先进先出，两个出口，一端只能进数据，一端只能出数据，不允许遍历
```
que.empty();
que.size();

que.push(i); // 队尾添加元素
que.pop(); // 队头移除元素

que.back();
que.front();
```

## list
> **链表**，非连续的存储结构，数据元素的逻辑顺序通过链表中的指针链接实现

> 链表由一系列结点组成
>> 结点：一个是存储数据元素的**数据域**；一个是存储下一个结点地址的**指针域**

> 双向循环链表
```
lst.empty();
lst.size();
lst.resize(num, elem);

lst.push_back(i);
lst.push_front(i);
lst.pop_back();
lst.pop_front();
lst.insert(lst.begin(), elem);
lst.insert(lst.begin(), n, elem);
lst1.insert(lst1.begin(), lst2.begin(), lst2.end());
lst.clear();
lst.erase(lst.begin());
lst.remove(elem);

lst.front();
lst.back();

lst.reverse(); // 反转链表
lst.sort(); // 排序
```

## set/multiset
> **集合**，关联式容器，底层结构用二叉树（红黑树）实现

> 数据插入时会自动被排序

> set不允许容器中有重复元素，multiset允许容器中有重复元素
```
set.empty();
set.size();

set.insert(elem);
set.clear();
set.earse(set.begin());

set.find(key); // 查找key元素是否存在，若存在，返回该元素的迭代器；若不存在，返回set.end()
set.count(key); // 统计key元素个数
```

## pair
```
pair<type, type> p (value1, value2);
pair<type, type> p  = make_pair(value1, value2);
p.first;
p.second;
```

## map/multimap
> map中的所有元素都是pair

> pair中第一个元素为key（键值），第二个元素为value（实值）

> 所有元素根据元素的键值自动排序

> map/multimap属于关联式容器，底层结构通过二叉树（红黑树）实现

> map不允许容器中有重复的key值；multimap允许容器中有重复的key值
```
map<int, int> m;
m.insert(pair<int, int>(1, 10));

m.size();
m.empty();

m.insert(pair<int, int>(1, 10));
m.insert(make_pair(1, 10));
m[4] = 40; // 不建议用来插入，但可以用来访问

m.erase(m.begin());
m.clear();

m.find(key);
m.count(key);
```

## 常用算法

### 常用遍历算法
```
for_each(iterator beg, iterator end, _func); // 遍历容器元素
transform(iterator beg1, iterator end1, iterator beg2, _func); // 搬运容器到另一个容器中
```

### 常用查找算法
```
find(iterator beg, iterator end, value); // 查找元素；返回迭代器
find_if(iterator beg, iterator end, _Pred); // 按条件查找元素；返回迭代器
adjacent_find(iterator beg, iterator end); // 查找相邻重复元素
binary_search(iterator beg, iterator end, value); // 二分查找法；返回bool值
count(iterator beg, iterator end, value); // 统计元素个数
count_if(iterator beg, iterator end, _Pred); // 按条件统计元素个数
```

### 常用排序算法
```
sort(iterator beg, iterator end, _Pred); // 对容器内元素进行排序
random_shuffle(iterator beg, iterator end); // 洗牌，指定范围内的元素随机调整次序
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); // 容器元素合并，并存储到另一容器中
reverse(iterator beg, iterator end); // 反转指定范围的元素
```

###  常用拷贝和替换算法
```
copy(iterator beg, iterator end, iterator dest); // 容器内指定范围的元素拷贝到另一容器中
replace(iterator eng, iterator end, oldvalue, newvalue); // 容器内指定范围内的旧元素替换为新元素
repalce_if(iterator beg, iterator end, _Pred, newvalue); // 容器内指定范围满足条件的旧元素替换为新元素
swap(container c1, container c2); // 互换两个容器元素
```

### 常用算术生成算法
```
accumulate(iterator beg, iterator end, value); // 计算容器元素累计总和
fill(iterator beg, iterator end, value); // 向容器中添加元素
```

### 常用集合算法
```
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); // 求两个容器的交集
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); // 求两个容器的并集
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); // 求两个元素的差集
```