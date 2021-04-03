-- mysql建表约束



-- 主键约束
它能够唯一确定一张表中的一条记录，也就是我们通过给某个字段添加约束，就可以使得该字段不重复且不为空
mysql> create table user(
    -> id int primary key,-- 主键约束，id不可重复，不能为空
    -> name varchar(20),
    -> );
mysql> insert into user values(1, '张三');
mysql> insert into user values(2, '张三');
mysql> insert into user values(2, '李四'); -- 报错，id不可重复
mysql> insert into user values(NULL, '王五'); -- 报错，id不可为空

mysql> create table user2(
    -> id int,
    -> name varchar(20),
    -> password varchar(20),
    -> primary key(id, name)-- 联合主键，只要联合的主键加起来不重复就可以
    -> );
mysql> insert into user2 values(1, '张三','123');
mysql> insert into user2 values(1, '李四','123');
mysql> insert into user2 values(2, '张三','123');
mysql> insert into user2 values(NULL, '王五','123'); -- 报错，联合主键，id也不能为空

-- 自增约束
mysql> create table user3(
    -> id int primary key auto_increment,--自增约束，自动创建id
    -> name varchar(20)
    -> );
mysql> insert into user3 (name) values('张三');
-- 如果创建表时忘记主键约束了？该怎么办？
mysql> create table user4(
    -> id int,
    -> name varchar(20)
    -> );
-- 修改表结构，添加主键
mysql> alter table user4 add primary key(id);
-- 如何删除？
mysql> alter table user4 drop primary key;
-- 如何修改？
mysql> alter table user4 modify id int primary key;



-- 唯一约束
-- 约束修饰的字段的值不可以重复
mysql> create table user5(
    -> id int,
    -> name varchar(20)
    -> );
mysql> create table user5(
    -> id int,
    -> name varchar(20)
    -> unique(name)
    -> );
mysql> create table user5(
    -> id int,
    -> name varchar(20) unique
    -> );
mysql> alter table user5 add unipue(name);
mysql> insert into user5 values('1', '张三');
mysql> insert into user5 values('1', '李四');
mysql> insert into user5 values('2', '张三');-- 报错，名字不能重复
-- 如何删除唯一约束？
mysql> alter table user5 drop index name;
-- 如何使用modify添加唯一约束？
mysql> alter table user5 modify name varchar(20) unique;



-- 非空约束
-- 修饰的字段不能为空NULL
mysql> create table user6(
    -> id int,
    -> name varchar(20) not null
    -> );
mysql> insert into user6 values('1');-- 报错



-- 默认约束
-- 当插入字段值的时候，如果没有传值，就会使用默认值
mysql> create table user7( 
    -> id int,
    -> name varchar(20),
    -> age int default 10
    -> );
mysql> insert into user7 (id, name) values(1, '张三');
-- 如果传了值就不会使用默认值



-- 外键约束
-- 涉及到两个表：父表，子表
-- 主表，副表

-- 班级表
mysql> create table classes(
    -> id int primary key,
    -> name varchar(20)
    -> );
-- 学生表
mysql> create table students(
    -> id int primary key,
    -> name varchar(20),
    -> class_id int,
    -> foreign key(class_id) references classes(id)
    -> );

mysql> insert into classes values(1, '1班');
mysql> insert into classes values(2, '2班');
mysql> insert into classes values(3, '3班');
mysql> insert into classes values(4, '4班');

mysql> insert into students values(1001, '张三', 1);
mysql> insert into students values(1002, '张三', 2);
mysql> insert into students values(1003, '张三', 3);
mysql> insert into students values(1004, '张三', 4);
mysql> insert into students values(1005, '张三', 5);-- 报错
-- 主表classes中没有的数据值，在副表中，是不可以使用的
mysql> delete from classes where id=4;-- 报错
-- 主表中的记录被副表引用，是不可以被删除的















