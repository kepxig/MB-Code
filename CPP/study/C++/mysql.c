#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main() {
    MYSQL conn;
    int res;
    MYSQL_RES * result;
    MYSQL_ROW row;
    mysql_init(&conn);

    if (mysql_real_connect(&conn, "localhost", "root", "Password123!", "person", 0, NULL, 0)) {
        printf("coneect mysql successful\n请选择功能\n");
        int choose;
        char str1[20], str2[20];
        char insert_query[80];
        char delete_query[50] = "delete from person where name='";
        char select_query[] = "select * from person";
        char update_query[80];
        printf("1.insert\n2.select\n3.delete\n4.update\n");
        while (scanf("%d", &choose)) {
            switch (choose) {
            case 1:    //insert
                printf("姓名 年龄：");
                memset(insert_query, 0, sizeof(insert_query));
                scanf("%s %s", str1, str2);
                strcat(insert_query, "insert into person(name,age) values('");
                strcat(insert_query, str1);
                strcat(insert_query, "',");
                strcat(insert_query, str2);
                strcat(insert_query, ")");
                printf("SQL语句: %s\n", insert_query);
                res = mysql_query(&conn, insert_query);
                if (!res) {
                    printf("insert %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
                }
                else {
                    printf("insert error\n");
                }
                break;
            case 2:    //select            
                printf("SQL语句: %s\n", select_query);
                if (mysql_query(&conn, select_query) != 0) {
                    fprintf(stderr, "查询失败\n");
                    exit(1);
                }
                else {
                if ((result = mysql_store_result(&conn)) == NULL) {
                        fprintf(stderr, "保存结果集失败\n");
                        exit(1);
                    }
                    else {
                        while ((row = mysql_fetch_row(result)) != NULL) {
                            printf("name is %s , ", row[1]);
                            printf("age is %s\n", row[2]);
                        }
                    }
                }
                break;
            case 3:    //delete
                printf("要删除的姓名\n");
                scanf("%s", str1);
                strcat(delete_query, str1);
                strcat(delete_query, "'");            
                printf("SQL语句: %s\n", delete_query);
                res = mysql_real_query(&conn, delete_query, (unsigned int)strlen(delete_query));
                if (!res) {
                    printf("delete successful\n");
                }
                else {
                    printf("delete error\n");
                }
                break;
            case 4:     //update
                printf("要修改的姓名\n");
                scanf("%s", str1);
                printf("要修改为的年龄\n");
                scanf("%s", str2);
                strcat(update_query, "update person set age='");
                strcat(update_query, str2);
                strcat(update_query, "' where name='");
                strcat(update_query, str1);
                strcat(update_query, "';");
                printf("SQL语句: %s\n", update_query);
                res = mysql_real_query(&conn, update_query, (unsigned int)strlen(update_query));
                if (!res) {
                    printf("update successful\n");
                }
                else {
                    printf("update error\n");
                }
                break;

            }
        }
        mysql_close(&conn);
    }
    return 0;
}
