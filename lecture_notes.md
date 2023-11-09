# Lecture Notes
\* Will be taking memos of stuff I didn't know

\* Lecture materials are found [here](https://eeic-software1.github.io/2023/)

## Main Objective
- **全員がポインタを理解することを目的とします**

## Cheatsheettttttt

```C
#include <typeinfo>
#include <stdio.h>

// 一次元配列と二次元配列について、型の詳細。
// typeinfoというc++の機能を使えば、以下のように型を表示できる。
// typeid(変数).name() で型が表示される。
// そのままだと見にくいので、c++filtというコマンドで見やすく出来る
//
// How to run:
// (1) コンパイル。gccではなくてg++なので注意。つまりこれはcではなくc++プログラム
//   $ g++ main.cpp
// (2) 実行。パイプでc++filtというプログラムに渡すと、見やすくなる。
//    （ただし、文字列置換を行うので、普通のprintfの出力がおかしくなるかもしれないので注意）
//   $ ./a.out | c++filt -t 


int main(int argc, char *argv[]) {
    // =================== 一次元配列の場合 =================== 
    int a[] = {1, 2, 3};
    int *p;
    p = a;

    // 次のように、配列の型は「int [3]」、int型へのポインタは「int*」となる
    printf("=== 0 ===\n");
    printf("%s\n", typeid(a).name());  // int [3]
    printf("%s\n", typeid(p).name());  // int*

    // 配列とポインタは同じように扱えると習ったが、それでも、
    // int [3] と int*は型が違うじゃないかと思うかもしれない。
    // これはルールなので仕方ないのだが、一つの説明として、
    // a + 0 を考えてみる。 a + 0 の型は実はポインタと同じ int* である。
    // a + 0 も a も似たようなものだと考えると、この事実から、
    // 配列をポインタと同じように扱えることがわかるかもしれない。
    // 配列が関数に渡されるときは、こっちになっていると思えばOK。
    // 逆に、複雑な配列に対してそれをポイントする型がわからないときは、
    // "+0"して型を調べてみるといいかもしれない。
    printf("%s\n", typeid(a + 0).name());  // int*

    // 「a」だけの場合、それは実体としての配列（intを3つ分確保）を指している。
    // sizeofも12になる。 一方、「a + 0」とした場合、
    // それをポインタだとコンパイラは解釈する。sizeofも8になる。
    // この二つはポインタを経由して扱う場合は同じもの。なので、
    // int *p = aと出来る。
    // 結論として、型が「int [3]」のものは、「int*」でポイント出来る。
    printf("%p %p\n", a, a + 0);  // 値は同じ。 0x7ffd864060b4 0x7ffd864060b4
    printf("%lu\n", sizeof(a));      // sizeofは違う：12
    printf("%lu\n", sizeof(a + 0));  // sizeofは違う：8


    // 「a + 1」のように指定すると、「p + 1」と全く同じにふるまう
    printf("=== 1 ===\n");
    printf("%s\n", typeid(a + 1).name());  // int* 
    printf("%s\n", typeid(p + 1).name());  // int*
    printf("%s\n", typeid(*(a + 1)).name());  // int
    printf("%s\n", typeid(*(p + 1)).name());  // int


    // *(a + i) とa[i]は同じ
    printf("=== 2 ===\n");
    printf("%s\n", typeid(&a[1]).name());  // int*  ちなみにこれは &(a[1])のこと
    printf("%s\n", typeid(&p[1]).name());  // int*
    printf("%s\n", typeid(a[1]).name());  // int
    printf("%s\n", typeid(p[1]).name());  // int


    printf("=== 3 ===\n");
    // &aと&pは型も値も違う（week 4を参照）

    // &aは何かを考えることは難しい。結論はint (*)[3] である。
    // すなわち、「int 3つ」を単位とするポインタである。
    // それはなぜだろうか？例えば変数一つの場合を考える。
    // int n;
    // int *p;
    // p = &n;
    // このように、「int 1つ」であるnのアドレス（&n）を代入すべきポインタは、
    // int *である。すなわち、「int 1つ」を単位とするポインタである。
    // この議論を拡張し、int a[3]; とすると、
    // 「int 3つ」であるaのアドレス（&a）を代入すべきポインタは、
    // int (*)[3] すなわち、「int 3つ」を単位とするポインタである、と言える
    printf("%s\n", typeid(&a).name());  // int (*)[3]

    // &pは単純にポインタのさらにアドレスなので、ポインタのポインタ
    printf("%s\n", typeid(&p).name());  // int**

    // &aはaと同じ。&pはポインタ変数そのもののアドレス
    printf("%p %p\n", &a, &p);  // 違う: 0x7ffd864060b4 0x7ffd86406098


    // =================== 二次元配列の場合 =================== 
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p2)[3];
    p2 = arr; // p2はarrを二次元配列として指すポインタ。

    // 授業で習った通り、arrは二次元配列 int [2][3] で、
    // p2は「int 3つ分を単位とするポインタ」
    // では、int [2][3] を指すポインタが int (*)[3]だと
    // どうすればわかるだろうか？
    printf("=== 4 ===\n");
    printf("%s\n", typeid(arr).name());  // int [2][3]
    printf("%s\n", typeid(p2).name());   // int (*)[3]

    // 一次元配列の例で見た通り、0を足すと、コンパイラは
    // arrをポインタとして解釈する。そのときの型を見ると、
    // それは、arrをポインタとして指すときの型。
    // なので、この場合、p2と型が同じなので、OKということになる。
    printf("%s\n", typeid(arr + 0).name());  // int (*)[3]


    // 添え字を使って各行にアクセスする場合。これは一次元配列そのものになる
    printf("=== 5 ===\n");    
    printf("%s\n", typeid(arr[0]).name());  // int [3]
    printf("%s\n", typeid(p2[0]).name());   // int [3]
    printf("%s\n", typeid(arr[0] + 0).name()); // int*
    printf("%s\n", typeid(p2[0] + 0).name());  // int*


    // arrやp2に&をすると次のようになる。値も異なる。
    printf("=== 6 ===\n");    
    printf("%s\n", typeid(&arr).name());  // int (*)[2][3]
    printf("%s\n", typeid(&p2).name());  // (**)[3]



    printf("=== 7 ===\n");    
    // 以下は全てアドレスの値は同じだが、型は異なる
    // 0x7ffcc93804a0 0x7ffcc93804a0 0x7ffcc93804a0 0x7ffcc93804a0 0x7ffcc93804a0
    printf("%p %p %p %p %p\n", &arr, arr, &arr[0], arr[0], &arr[0][0]);

    // &arrは、二次元配列そのものを一単位として扱う。よって、
    // 「intが2 * 3個」を一つの単位とする。
    // これは一次元配列名に&をしたときと同じ。難しいが、普段は使わない
    printf("%s\n", typeid(&arr).name());       // int (*)[2][3]   

    // arrは二次元配列そのもの。これはそのまんま。
    printf("%s\n", typeid(arr).name());        // int [2][3]

    // 再度の注意として、arrに0を足すと、これをポインタとして解釈してくれる
    printf("%s\n", typeid(arr + 0).name());    // int (*)[3]

    // arr[0]は一行目の一次元配列そのもの
    printf("%s\n", typeid(arr[0]).name());    // int [3]

    // 再度の注意として、arr[0]に0を足すと、これをポインタとして解釈してくれる
    printf("%s\n", typeid(arr[0] + 0).name());    // int*

    // &arr[0]は難しい。考え方として、次の二通りがあると思う
    // (1) &arr[0]（アンド＋添え字アクセス）は arr + 0（変数名＋オフセット）と同じ
    //     というルールを適用すると、上のarr + 0になる、と覚える
    // (2) arr[0]は一次元配列そのものだった。一次元配列そのものに&をつけると、
    //     配列長を単位とするポインタになったことを思い出す
    //     （上のほうの === 3 === のところを参照）
    printf("%s\n", typeid(&arr[0]).name());    // int (*)[3]

    // arr[0][0]はintなので、そのポインタ。
    printf("%s\n", typeid(&arr[0][0]).name()); // int*


    // =================== 三次元配列の場合も同様 =================== 
    int arr2[2][3][4] = {
        {{ 1,  2,  3,  4}, { 5,  6,  7,  8}, { 9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    int (*p3)[3][4];
    p3 = arr2; // p3はarr2を三次元配列として指すポインタ。
    printf("=== 8 ===\n");
    printf("%s\n", typeid(arr2).name());      // int [2][3][4]
    printf("%s\n", typeid(p3).name());        // int (*)[3][4]
    printf("%s\n", typeid(arr2 + 0).name());  // int (*)[3][4]

    return 0;
}
```
## Lecture 1
Date: 2023/10/05; [Source code](week1)
### CLI
- Use `man` to show options of command
```shell
man mkdir
```
### Basic Data Types
- Can call a var name without value (int stands for integer), then initialize!
```C
int height, width;
```

- Once integer is initialized, it is mutable
```C
int height = 5;  // 宣言と同時に代入（初期化）
height = 12;  // 値の上書き
```
- **List of integer data types**

![](lecture_notes_pic/week1_1.png)

- For real numbers, there are **float** and **double**

- **char** value has a max of 127, if over that, it will implicitly be changed to an **int**
```C
char c3 = 140;
printf("%d", c3);
>>> -116
```

- Variable values are stored in 64bit integer addresses and when called with `&var_name`, the leading address will be represented in base-16
```C
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

```C
int x = 0, y = 0, a = 0, b = 0;
x = ++a;  // xは1になる
y = b++;  // yは0になる
```

- Difference of casting and initiating as a literal

```C
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

```C
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
```C
int a[3];  // int型が3つ並んだ配列
a[0] = 12;
a[1] = 3;
a[2] = 5;   // 最後。
```
OR
```C
int a[3] = {12, 3, 5};

// さらに省略。
int a[] = {12, 3, 5};
```
For n-dimension arrays,
```C
int mat[2][3] = {
    {32,  5, 76},
    { 1, 12,  8}
};
```
- In memory, a 1-d array will store 3 `int`s in consecutive addressses. n-d arrays will store elements first row ([0][0]..[i]) first.

### Loops
- **Break** leaves the loop. **Continue** skips the loop for one increment only

- **Switch** is like an if statement
```C
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
```C
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
```C
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
```C
int i;
float f;
f = i = 23.5f;
```
- Both will be 23. Bcs `f = (i = 23.5f)`

Why does `a < b < c` not work?

- `<` is a left bond. It will be evaluated to `(-20 < -10) < -2` then `1 < -2`

## Lecture 3

### Strings and Characters
In `C`, we differentiate strings and characters. Characters are singular letters and the whole thing is a string (文字列). **But both are called with `char`.**
```C
int main() {
    char s[6] = "hello";
    char s[] = "hello";
}
```
Characters are stored very similarly to arrays
![](lecture_notes_pic/string_storage.png)


```C
char s2[8] = "hello"; // {'h', 'e', 'l', 'l', 'o', '\0', '\0', '\0'};
char s3[3] = "hello";  // {'h', 'e', 'l'};
```

Just like arrays, the address of a string is the address of the first character.

```C
int a[3] = {1, 2, 3};
printf("%p %p\n", a, &a[0]); // 同じになる。例えば 0x7fffd6711a90 0x7fffd6711a90
```

Not possible to compare Strings because using `==` will compare address instead.
```C
char s1[] = "abc";
char s2[] = "abc";
if (s1 == s2) { ... }  // 想定した挙動にならない。常に偽になる
```

### sizeof()
sizeof returns the number of bytes. If an array is given, will multiply.
```C
printf("%lu\n", sizeof(char)); // 1
printf("%lu\n", sizeof(int));  // 4

int a[] = {1, 2, 3};
printf("%lu\n", sizeof(a));  // 12
```

### Inputing an array as function
```C
int count_spaces(char s[]) {
    int ct = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ') {
            ++ct;
        }
    }
    return ct;
}
```

When doing sizeof() for strings, it will count the last `'\0'`
```C
char s[] = "abc";
printf("%lu\n", sizeof(s)); // 4
```

### <string.h>
Functions for strings
- `strlen`: length of string. Without `'\0'`
- `strcpy`: copy a string
- `strcat`: concatenate a string
- `strcmp`: compare string

```C
int main() {
    char s1[] = "abc";
    unsigned long len = strlen(s1);  // 長さを取得
    printf("sizeof(s1): %lu, strlen(s1): %lu\n", sizeof(s1), len);  // sizeof: 4, strlen: 3

    char s2[10];  // 十分に長く確保
    strcpy(s2, "hello");
    printf("%s\n", s2);  // 文字列をコピー。 s2 = "hello" 的なもの。
    printf("sizeof(s2): %lu, strlen(s2): %lu\n", sizeof(s2), strlen(s2)); // sizeof: 10, strlen: 5

    char s3[10] = "hoge";  // 十分に長く確保
    printf("sizeof(s3): %lu, strlen(s3): %lu\n", sizeof(s3), strlen(s3)); // sizeof: 10, strlen: 4
    strcat(s3, "fuga");  // 文字列を結合する。stringのconcatenate
    printf("%s\n", s3); // "hogefuga"
    printf("sizeof(s3): %lu, strlen(s3): %lu\n", sizeof(s3), strlen(s3)); // sizeof: 10, strlen: 8

    char s4[] = "abc";
    char s5[] = "abcd";
    int cmp = strcmp(s4, s5); // 文字列の比較。s4 == s5的なもの。二つの文字列の辞書順に応じて、正か0か負になる
    printf("%d\n", cmp);  // ここでは-100
}

```
### Quiz
1. How to get an int from the string?
```C
int n = c - '0'
```
2. How to get the lowercase of a given character?
```C
c = c - 'A' + 'a';
```
3. `0`と、`'0'`と、`'\0'`と、`"0"`と、`"\0"`の違い
    - Integer
    - ASCII that represents 0
    - ASCII that represents NULL
    - String
    - String

### Transforming types
In C, types are transformed automatically.

Types are converted automatiaccaly when
1. Handling operations
2. Subtitution `int a = b`
3. When input does not matched defined in function
4. When output does not matched defined outside function

```C
char c = 12;     // 8 bit
short s = 34;    // 16 bit
int i = 56;      // 32 bit
float f = 1.0;   // 32 bit
double d = 2.0;  // 64 bit
i = i + c;       // i + cで、cがintに変換される
i = i + s;       // i + sで、sがintに変換される
f = f + i;       // f + iで、iがfloatに変換される
d = d + f;       // d + fで、fがdoubleに計算される
```
### Cast
```C
float quotient;
int dividend = 3, divisor = 2;

// キャスト無し
quotient = dividend / divisor; // 1.000

// キャストあり
quotient = (float) dividend / divisor;  // 1.5000
```

### Input and Outputs
Use `getchar()` and `putchar()` to take input and output

```C
#include <stdio.h>

int main() {
    int c = getchar();
    while (c != EOF) {
        putchar('/');  // 複写プログラムに加え、文字の間にスラッシュをいれる
        putchar(c);
        c = getchar();
    }
}
```
Use a `|` to combine shell commands
```shell
$ echo abcd | ./a.out
/a/b/c/d/
```

### Bash
Use `grep` to search for a word in ls by combining with ls
```Bash
ls -al | grep mkdir
```

## Lecture 4

### DEFINE!
We can define a constant variable using `#define N 5`. No matter where it is, all `N` will be substituted as 5.
```C
#define N 5

int main() {
    for (int i = 0; i < N ...)
}
```

### const

When passing a pointer to a function, we have access to the actual value and edit it. But this could lead to errors. `const` allows us to access but not change it
```C
int strlen3(const char *s) {
    const char *p = s;
    while (*s) {
        s++;
    }
    return s - p;
}
```
### Pointers
Think of pointers as a variable that holds another variable's address. The tricky part of pointers in C is that we use `*` to initiate pointers and also `*` to access the value of pointer.

```C
// We have to state what is the varaible's type when initiating pointer
double a = 10.0;
double *p;
p = &a;
```

Becareful that `*` just means pointer for the next variable

```C
int* p1, p2, p3; => p1 is pointer of int, p2 and p3 are ints
```

Make two varaibles point at the same memory space using pointers

```C
int a = 10;
int *p;
p = &a;  // p は aを指す

int *q; // もう一個ポインタを宣言
q = p;  // q = &a と同じ意味
```
![](https://eeic-software1.github.io/2023/img/4_pt2.png)

### Pointers as input of functions
In C, we could only get one return per function so instead, we could pass in pointers and change value pointed by pointers for multiple inputs.

```C
void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long) x;
    *frac_part = x - *int_part;
}

int main() {
    long n;
    double d;
    decompose(3.14, &n, &d)
}
```

When using the function decompose, we are passing a copy of each address. However, we can access the "real" value through the address, so we can edit the actual values.

### Returning a pointer
We can also create functions that return pointers.
```C
int *min(int *a, int *b) {
    if (*a < *b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int *ret;
    ret = min(&num1, *num2);
}
```
The function above will return the address of minimum value.

Btw, if you intitiate local varaible inside function, you cannot return the address of it.


### Quiz
```C
int a = 10;
int *p = &a;
```
What do these expressions mean?
- `*&a`

`a`
- `&*a`

error.
- `*&p`

p
- `&*p`

a's address.

### Pointer and arrays
```C
int a[3] = {12, 3, 5};
int *p = &a[0];  // &(a[0])のこと
int *p =&a; // Still same
*p = 2; // a become {2, 3, 5}
```

When incrementing address of array, we will go to the next elements

![](https://eeic-software1.github.io/2023/img/4_pt5.png)

The above is equivalent to,

```C
q = p + sizeof(int) * 2;
```

Why is the code below okay?
```C
for (int *p = &a[0]; p < &a[N]; ++p) { ... }
```
Because, although `int a[N]` is not defined, the address `&a[N]` is defined! Recall that in memory space, after the last element, there will be `!0`

![](https://eeic-software1.github.io/2023/img/4_pt7.png)

From the picture above, we realise that a pointer pointing at the start of an array is very similar to the just the array variable. But there are inherent differences


We can't equate it to a `NULL`
```C
int a[] = {1, 2, 3, 4, 5}, *p;
p = a;
int *r = NULL;
p = r;  // 出来る（ポインタにポインタを代入）
a = r;  // 出来ない（aは固定されている配列アドレスなので、別のものを代入できない）
```

Different `sizeof()`
```C
int a[] = {1, 2, 3, 4, 5}, *p;
p = a;
printf("sizeof(p): %lu\n", sizeof(p)); // sizeof(p): 8
printf("sizeof(a): %lu\n", sizeof(a)); // sizeof(a): 20
```

- 変数宣言時のint a[]とint *aは意味が違う。配列か。ポインタか。
- 関数引数のint a[]とint *aは同じで、どちらもint *a

### Strings and pointers

```C
char s[] = "hoge";
char *p = s;
```

**POINT!** The `sizeof` of char is `1` so `p+1` will equate be literally 1 + p.

```C
int strlen3(const char *s) {
    const char *p = s;
    while (*s) {
        s++;
    }
    return s - p;
}
```
Here, we are changing s but the `s` referred from `p` is kept constant. Which means that even if we change the value of the pointer s, the value seen from `p` is same.

### Initiating a string as a literal.....

```C
char amsg[] = "abc";
char *pmsg = "abc";
printf("%s %s\n", amsg, pmsg);  // abc abc
```
- Top: 4 char memory spaces to hold 'a', ... '\0'
- Bottom: Somewhere in program, literal "abc" is stored. Can be accessed, cannot be editted

```C
amsg = NULL;  // ダメ
pmsg = NULL;  // OK
amsg[0] = 'A';  // OK
pmsg[0] = 'A';  // ダメ
```

If we create two pointers pointing to the same literal, it will be stored in the same

### Finding largest value with pointer
```C
void find_largest(int a[], int n, int *max) {
    *max = a[0];
    for (int i = 0; i < n; i++) {
        if (*max < a[i]) {
            *max = a[i]
        }
    }
}

int main() {
    int ans;
    find_largest(arr, 3, &ans)
}
```
When passing an array to function, it acts as a pointer.
![](https://eeic-software1.github.io/2023/img/5_pt2.png)

## Lecture 5

### Pointer's pointer
Simple Example
```C
int a = 10;
printf("   a: %d\n", a);     // 10

int *p = &a;
printf("   p: %p\n",  p);    // 0xff5c   (以下、アドレスは全て人工的な例です)
printf("  *p: %d\n", *p);    // 10

int **pp = &p;
printf("  pp: %p\n",   pp);  // 0x51a5
printf(" *pp: %p\n",  *pp);  // 0xff5c
printf("**pp: %d\n", **pp);  // 10
```

pp is a pointer of pointer. *pp will return the address of p.

![](https://eeic-software1.github.io/2023/img/5_pt1.png)

Find minmax of array
```C
int main() {
    int *min, *max;
    int arr[] = {3, 6, 9, 10};
    minmax(arr, 4, &min, &max);
    printf("min: %d, max: %d", *min, *max);
}

void minmax(int a[], int n, int **minpointer, int **maxpointer) {
    *minpointer = &a[0];
    *maxpointer = &a[0];
    for (int i = 0; i < n; i++) {
        *minpointer = a[i] < **minpointer ? &a[i] : *minpointer;
        *maxpointer = a[i] > **maxpointer ? &a[i] : *maxpointer;
    }
}
```

When we do `int **minpointer` its just initiating a pointer to pointer. That pointer of pointer's value is first set to a[0]'s address.

### Pointers to nd array
```C
int arr[][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

int (*p)[3];  // 「int 3つ分」を1単位とするポインタ
p = arr;      // p と p + 1 の間の値（アドレス）の差は12（つまりint3つ分）
```
ここでの結論は、

- 型Tで幅Wの二次元配列arrを考える。`T arr[][W]`;
- このarrへのポインタpは、`T (*p)[W] = arr`;と書ける
- このポインタは`sizeof(T) * W`を単位とする。
- Wは省略できない

ということです。




