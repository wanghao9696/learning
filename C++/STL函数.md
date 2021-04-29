

## string
```
int pos = str1.find(str2); // 查找
int pos = str1.rfind(str2); // 反向查找

str1.replace(1, 3, str2); // 替换

int ret = str1.compare(str2); // 比较

str[i]等价于str.at(i) // 存取

str.insert(3, str2); // 插入
str.earse(1, 3); // 删除

string str2 = str1.substr(1, 3); // 截取子串
```

## vector
```
v1.empty(); // 判读是否为空
v1.capacity(); // 返回容器容量 0 1 2 4 4 8 8 8 8 16 ...
v1.size(); // 返回容器元素个数
v1.resize(int num, elem); // 重新指定容器

v1.push_back(i);
v1.pop_back(i);
```
