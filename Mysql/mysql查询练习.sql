-- mysql查询练习

-- 学生表
--Student
--学号
--姓名
--性别
--出生年月日
--所在班级
mysql> create table student(
    -> sno varchar(20) primary key,
    -> sname varchar(20) not null,
    -> ssex varchar(20) not null,
    -> sbirthday datetime,
    -> class varchar(20)
    -> );
insert into student values('101', '曾华', '男', '1977-09-01', '95033');
insert into student values('102', '匡明', '男', '1975-10-12', '95031');
insert into student values('103', '王丽', '女', '1976-01-23', '95033');
insert into student values('104', '李军', '男', '1976-02-20', '95033');
insert into student values('105', '王芳', '女', '1975-02-10', '95031');
insert into student values('106', '陆君', '男', '1974-06-03', '95031');
insert into student values('107', '王尼玛', '男', '1976-02-20', '95033');
insert into student values('108', '张全蛋', '男', '1975-02-10', '95031');
insert into student values('109', '赵铁柱', '男', '1974-06-03', '95031');

-- 教师表
--Teacher
--教师编号
--教师姓名
--教师性别
--出生年月日
--职称
--所在系
mysql> create table teacher(
    -> tno varchar(20) primary key,
    -> tname varchar(20) not null,
    -> tsex varchar(10) not null,
    -> tbirthday datetime,
    -> prof varchar(20) not null,
    -> depart varchar(20) not null
    -> );
insert into teacher values('804', '李诚', '男', '1958-12-02', '副教授', '计算机系');
insert into teacher values('856', '张旭', '男', '1969-03-12', '讲师', '电子工程系');
insert into teacher values('825', '王萍', '女', '1972-05-05', '助教', '计算机系');
insert into teacher values('831', '刘冰', '女', '1977-08-14', '助教', '电子工程系');

-- 课程表
--Course
--课程号
--课程名称
--教师编号
mysql> create table course(
    -> cno varchar(20) primary key,
    -> cname varchar(20) not null,
    -> tno varchar(20) not null,
    -> foreign key(tno) references teacher(tno)
    -> );
insert into course values('3-105', '计算机导论', '825');
insert into course values('3-245', '操作系统', '804');
insert into course values('6-166', '数字电路', '856');
insert into course values('9-888', '高等数学', '831');


-- 成绩表
--Score
--学号
--课程号
--成绩表
mysql> create table score(
    -> sno varchar(20) not null,
    -> cno varchar(20) not null,
    -> degree decimal,
    -> foreign key(sno) references student(sno),
    -> foreign key(cno) references course(cno),
    -> primary key(sno, cno)
    -> );
insert into score values('103', '3-245', '86');
insert into score values('105', '3-245', '75');
insert into score values('109', '3-245', '68');
insert into score values('103', '3-105', '92');
insert into score values('105', '3-105', '88');
insert into score values('109', '3-105', '76');
insert into score values('103', '6-166', '85');
insert into score values('105', '6-166', '79');
insert into score values('109', '6-166', '81');



-- 查询练习

--1.查询student表的所有记录
select * from student;

--2.查询student表中所有记录的sname，ssex和class列
select sname, ssex, class from student;

--3.查询教师所有单位即不重复的depart列
select depart from teacher;
select distinct depart from teacher;-- 去重

--4.查询score表中成绩在60-80之间的所有记录
--查询区间
select * from score where degree between 60 and 80;
select * from score where degree > 60 and degree < 80;

--5.查询score表中成绩为85，86和88的记录
--“或”关系
select * from score where degree in(85, 86, 88);

--6.查询student表中“95031”班或性别为“女”的同学记录
select * from student where class='95031' or ssex='女';

--7.以class降序查询student表中的所有记录
--升序、降序
select * from student order by class desc;--降序
select * from student order by class asc;--升序
select * from student order by class;--默认升序

--8.以cno升序，degree降序查询score表中的所有记录
select * from score order by cno asc, degree desc;

--9.查询“95031”班的学生人数
--统计
select count(*) from student where class='95031';

--10.查询score表中的最高分的学生学号和课程号（子查询或者排序）
select sno,cno from score where degree=(select max(degree) from score);

--11.查询每门课的平均成绩
select avg(degree) from score where cno='3-105';
--全部课程
-- group by分组
select cno,avg(degree) from score group by cno;

--12.查询score表中至少有2名学生选修的并以3为开头的课程的平均分数
select cno,avg(degree) from score group by cno having count(cno)>=2 and cno like '3%';

--13.查询分数大于70小于90的sno列
select sno,degree from score where degree>70 and degree < 90;

--14.查询所有学生的sname，cno，degree列
select sname,cno,degree from student,score where student.sno=score.sno;

--15.查询所有学生的sno，cname，degree列
select sno,cname,degree from course,score where course.cno=score.cno;

--16.查询所有学生的sname，cname，degree列
select sname,cname,degree,student.sno as stu_sno,score.sno,course.cno,score.cno as cou_stu from student,course,score 
where student.sno=score.sno and course.cno=score.cno;

--17.查询“95031”班学生每门课的平均分
select cno,avg(degree) from score where sno in (select sno from student where class='95031') group by cno;

--18.查询选修“3-105”课程的成绩高于“109”号同学“3-105”成绩的所有同学的记录
select * from score where cno='3-105' and degree>(select degree from score where sno='109' and cno='3-105');

--19.查询成绩高于学号为“109”、课程号为“3-105”的成绩的所有记录
select * from score where degree>(select degree from score where sno='109' and cno='3-105');

--20.查询和学号为108，101的同学同年出生的所有学生的sno，sname，sbirthday列
select * from student where year(sbirthday) in (select year(sbirthday) from student where sno in (108,101));

--21.查询张旭教师任课的学生成绩
select * from score where cno=(select cno from course where tno=(select tno from teacher where tname='张旭'));

--22.查询选修某课程的同学人数多于5人的教师姓名
select tname from teacher where tno=(select tno from course where cno=(select  cno from score group by cno having count(*)>5));

--23.查询95033班和95031班全体学生记录
select * from student where class in('95031', '95038');

--24.查询存在85分以上成绩的cno
select cno,degree from score where degree>85;

--25.查询计算机所有教师所教课程的成绩表
select * from score where cno in (select cno from course where tno in (select tno from teacher where depart='计算机系'));

--26.查询计算机系和电子工程系不同职称的教师的tname和prof
select * from teacher where depart='计算机系' and prof not in(select prof from teacher where depart='电子工程系')
union
select * from teacher where depart='电子工程系' and prof not in(select prof from teacher where depart='计算机系');

--27.查询选修编号为“3-105”课程且成绩至少高于选修编号为“3-245”的同学cno，sno，degree，并按defree从高到低排序
select * from score 
where cno='3-105' 
and degree>any(select degree from score where cno='3-245')
order by degree desc;--any表示任意一个

--28.查询选修编号为“3-105”课程且成绩高于选修编号为“3-245”的同学cno，sno，degree
select * from score 
where cno='3-105' 
and degree>all(select degree from score where cno='3-245')
order by degree desc;--all表示所有

--29.查询所有教师和同学的name，sex，birthday
select tname as name,tsex as sex,tbirthday as birthday from teacher
union
select sname,ssex,sbirthday from student;--利用as取别名

--30.查询所有女教师和女同学的name，sex，birthday
select tname as name,tsex as sex,tbirthday as birthday from teacher where tsex='女'
union
select sname,ssex,sbirthday from student where ssex='女';

--31.查询成绩比该课程成绩平均成绩低的同学的成绩表
--把score表分成a，b两个
select * from score a where degree < (select avg(degree) from score b where a.cno=b.cno);

--32.查询所有任课教师的tname和depart
select tname,depart from teacher where tno in (select tno from course);

--33.查询至少有两名男生的班号
select class from student where ssex='男' group by class having count(*)>1;

--34.查询student表中不姓王的同学记录
select * from student where sname not like '王%';

--35.查询student表中没喝学生的姓名和年龄
select sname,year(now)-year(sbirthday) as '年龄' from student;

--36.查询student表中最大和最小的sbirthday日期值
select max(sbirthday) as '最大',min(sbirthday) as '最小' from student order by sbirthday;

--37.以班号和年龄从大到小的顺序查询student表中的全部记录
select * from student order by class desc,sbirthday;

--38.查询男教师及其所上的课程
select * from course tno in (select tno from teacher where tsex='男');

--39.查询最高分同学的sno，cno，degree列
select * from score where degree=(select max(degree) from score);

--40.查询和“李军”同性别的所有同学的sname
select sname from student where ssex=(select ssex from student where sname='李军');

--41.查询和李军同性别并且同班
select sname from student 
where ssex=(select ssex from student where sname='李军')
and class=(select class from student where sname='李军');

--42.查询所有选修计算机导论课程的男同学的成绩表
select * from score
where cno=(select cno from course where cname='计算机导论')
and sno in (select sno from student where ssex='男');

--43.查询所有同学的sno，cno，grade列
create table grade(low int(3), upp int(3), grade char(1));
insert into grade values(90, 100, 'A');
insert into grade values(80, 89, 'B');
insert into grade values(70, 79, 'C');
insert into grade values(60, 69, 'D');
insert into grade values(0, 59, 'E');

select sno,cno,grade from score,grade where degree between low and upp;







