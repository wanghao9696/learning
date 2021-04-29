

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
```
v1.empty(); // 判读是否为空
v1.capacity(); // 返回容器容量 0 1 2 4 4 8 8 8 8 16 ...
v1.size(); // 返回容器元素个数
v1.resize(int num, elem); // 重新指定容器

v1.push_back(i);
v1.pop_back(i);
v1.insert(v1.begin()+2, 2, 8); // 第三个位置开始插入2个8
v1.erase(v1.begin(), v1.begin()+2) // 删除前两个元素
v1.clear(); // 等价于v1.erase(v1.begin(), v1.end())

v1.front();
v1.back();
```
