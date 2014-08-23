use qtdb;
create table qt_user
(
userid    smallint(2) primary key,  
username  varchar(100),			 
usertype  tinyint(1),   			 /*用户类型: -1 admin超级用户, 0 普通用户, 1 特别用户*/
userpassword   varchar(100),		 /*用户密码*/
userreserve_1  varchar(100),		/*保留字段1*/
userreserve_2  varchar(100),		/*保留字段2*/
userreserve_3  varchar(100),		/*保留字段3*/
userdate		date				/*用户创建时间*/
);

insert into qt_user values( 1, 'qtadmin', -1, 'qtadmin', '','','',  2014-04-29);
insert into qt_user values( 2, 'test', 0, 'test', '', '', '', 2014-4-29);

