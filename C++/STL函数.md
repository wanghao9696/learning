

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
```