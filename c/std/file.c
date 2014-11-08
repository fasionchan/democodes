/**
 * FileName:   file.c
 * Author:     Chen Yanfei
 * @contact:   fasionchan@gmail.com
 * @version:   $Id$
 *
 * Description:
 *
 * Changelog:
 *
 **/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 打开data.txt文件
    FILE *f = fopen("data.txt", "r");
    if (NULL == f) {
        perror("fopen error");
        return -1;
    }

    // 查看文件描述符
    int fd = fileno(f);
    if (-1 == fd) {
        perror("fileno error");
        return -1;
    }
    printf("fd=%d\n", fd);

    // 文件流错误检查
    if (ferror(f)) {
        printf("file stream has error\n");
        return -1;
    }

    // EOF检查
    if (feof(f)) {
        printf("file stream is ends\n");
        return -1;
    }

    // 逐行读
    char *line_buf = NULL;
    size_t buf_len = 0;
    ssize_t line_len;
    while ((line_len = getline(&line_buf, &buf_len, f)) != -1) {
        if ('\n' == line_buf[line_len]) {
            line_buf[--line_len] = '\0';
        }
        printf("read % 5d bytes line: %s", line_len, line_buf);
    }

    // 记得释放line_buf内存！！！
    free(line_buf);
    line_buf = NULL;
    buf_len = 0;

    // 文件偏移设为文件头
    if (fseek(f, 0, SEEK_SET) == -1) {
        perror("fseek error");
        return -1;
    }

    // 查看文件偏移
    long offset = ftell(f);
    if (-1 == offset) {
        perror("ftell");
        return -1;
    }
    else {
        printf("ftell=%d\n", offset);
    }

    // 另一种方式逐行读：指定行分隔符
    char delim = '\n';
    while ((line_len = getdelim(&line_buf, &buf_len, delim, f)) != -1) {
        if (delim == line_buf[line_len]) {
            line_buf[--line_len] = '\0';
        }
        printf("read % 5d bytes line: %s", line_len, line_buf);
    }

    // 再次记得释放line_buf内存！！！
    free(line_buf);
    line_buf = NULL;
    buf_len = 0;

    // 再次从头再来
    fseek(f, 0, SEEK_SET);

    // 循环读
    #define BUFSIZE     10
    #define READSIZE    BUFSIZE-1
    char buf[BUFSIZE];
    int total_bytes = 0, len;
    while ((len = fread(buf, 1, READSIZE, f)) != 0) {
        total_bytes += len;
        buf[len] = '\0';
        printf("%s", buf);
    }
    printf("\n%d bytes read\n", total_bytes);

    return 0;
}
