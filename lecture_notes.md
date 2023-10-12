# Lecture Notes
\* Will be taking memos of stuff I didn't know

\* Lecture materials are found [here](https://eeic-software1.github.io/2023/)

## Main Objective
- **全員がポインタを理解することを目的とします**

## Lecture 1
Date: 2023/10/05; [Source code](week1)
### CLI
- Use `man` to show options of command
```
man mkdir
```
### Basic Data Types
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

### More on Memory
- Memory in computer is made of a list 8-bit blocks. Each blocks has its own address of 64-bit integer

- For example, an int data type has 32 bits, so it is consisted of 4 blocks `00000000|00000000|00000000|00001010`


## Lecture 2
Date: 2023/10/12; [Source code](week2)

### Basic Operations
- `&&` : and, `||` : or

- Difference of `++a` and `a++`

```
int x = 0, y = 0, a = 0, b = 0;
x = ++a;  // xは1になる
y = b++;  // yは0になる
```

- Difference of casting and initiating as a literal

```
char c = 0;
int i = (int)c;

int i;
float f;
f = i = 23.5f;
```
 We cast on the top one and initializes 23.5 as a float on the bottom one

### Controls
- **文 vs 式**. 「式;」を「文」と呼ぶ

- **Blocks**

```
{
    // 複数の文をまとめてブロックにする
    a = 3;
    b += 2;
    int c = 123;  // ブロック内で宣言した変数はブロックの内側でしか使えない
}
// カッコの最後にはセミコロンが無いことに注意
// ブロックを抜けたあとではcにはアクセスできない
```

### Array
- Initiating arrays
```
int a[3];  // int型が3つ並んだ配列
a[0] = 12;
a[1] = 3;
a[2] = 5;   // 最後。
```
OR
```
int a[3] = {12, 3, 5};

// さらに省略。
int a[] = {12, 3, 5};
```
For n-dimension arrays,
```
int mat[2][3] = {
    {32,  5, 76},
    { 1, 12,  8}
};
```
- In memory, a 1-d array will store 3 `int`s in consecutive addressses. n-d arrays will store elements first row ([0][0]..[i]) first.

### Loops
- **Break** leaves the loop. **Continue** skips the loop for one increment only

- **Switch** is like an if statement
```
int school_year = 2;  // 大学2年生
switch (school_year)
{
    case 1:
    case 2:
        printf("You are studying at Komaba\n");
        break;
    case 3:
    case 4:
        printf("You are studying at Hongo\n");
        break;
    default:
        printf("Error\n");
        break;
}
```
### Function Semantics
- Function **passes a copy of the value** and can't update variabes.
```
void plus_one(int a) {
    a++;
}

int main () {
    int b = 10;
    plus_one(b);
    printf("%d\n", b); // 10のまま
}
```
- **Scopes**. Variable inside block is prioritized
```
int a = 0; // グローバル変数

void f() {
    int a = 3;  // グローバル変数と同じ名前のローカル変数
    ++a;
}
...
```

### Quiz
Why is `double a = 3 / 2` not `1.5`?

- 3 and 2 are integers so 3/2 will be `1`

What are values of i and f?
```
int i;
float f;
f = i = 23.5f;
```
- Both will be 23. Bcs `f = (i = 23.5f)`

Why does `a < b < c` not work?

- `<` is a left bond. It will be evaluated to `(-20 < -10) < -2` then `1 < -2`
