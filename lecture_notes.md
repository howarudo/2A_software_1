# Lecture Notes
\* Will be taking memos of stuff I didn't know

\* Lecture materials are found [here](https://eeic-software1.github.io/2023/)

## Main Objective
- **全員がポインタを理解することを目的とします**

## Lecture 1
Date: 2023/10/05; [Source code](week1)
#### CLI
- Use `man` to show options of command
```
man mkdir
```
#### Basic Data Types
- Can call a var name without value (int stands for integer), then initialize!
```
int height, width;
```

- Once integer is initialized, it is mutable
```
int height = 5;  // 宣言と同時に代入（初期化）
height = 12;  // 値の上書き
```
- **List of integer data types**

![](lecture_notes_pic/week1_1.png)

- For real numbers, there are **float** and **double**

- **char** value has a max of 127, if over that, it will implicitly be changed to an **int**
```
char c3 = 140;
printf("%d", c3);
>>> -116
```

- Variable values are stored in 64bit integer addresses and when called with `&var_name`, the leading address will be represented in base-16
```
printf("&p", &height);
>>> 0x7fff138be160
```

#### More on Memory
- Memory in computer is made of a list 8-bit blocks. Each blocks has its own address of 64-bit integer

- For example, an int data type has 32 bits, so it is consisted of 4 blocks `00000000|00000000|00000000|00001010`
