use qtdb;
create table qt_user
(
userid    smallint(2) primary key,  
username  varchar(100),			 
usertype  tinyint(1),   			 /*�û�����: -1 admin�����û�, 0 ��ͨ�û�, 1 �ر��û�*/
userpassword   varchar(100),		 /*�û�����*/
userreserve_1  varchar(100),		/*�����ֶ�1*/
userreserve_2  varchar(100),		/*�����ֶ�2*/
userreserve_3  varchar(100),		/*�����ֶ�3*/
userdate		date				/*�û�����ʱ��*/
);

insert into qt_user values( 1, 'qtadmin', -1, 'qtadmin', '','','',  2014-04-29);
insert into qt_user values( 2, 'test', 0, 'test', '', '', '', 2014-4-29);

