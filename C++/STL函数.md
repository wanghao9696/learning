

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
> 单端数组
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
> 双端数组
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
> 栈，先进后出，只有一个出口，不允许遍历
```
stk.empty();
stk.size();

stk.push(i); // 栈顶添加元素
stk.pop(); // 栈顶移除元素

stk.top(); // 返回栈顶的元素
```

## queue
> 队列，先进先出，两个出口，一端只能进数据，一端只能出数据，不允许遍历
```
que.empty();
que.size();

que.push(i); // 队尾添加元素
que.pop(); // 队头移除元素

que.back();
que.front();
```

## list
> 链表，非连续的存储结构，数据元素的逻辑顺序通过链表中的指针链接实现

> 链表由一系列结点组成
>> 结点：一个是存储数据元素的**数据域**；一个是存储下一个结点地址的**指针域**

> 双向循环链表
```

```