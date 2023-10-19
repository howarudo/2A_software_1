# The Unspoken Rule

## Background
Have you ever noticed that there's an **UNSPOKEN RULE** on urinals in men's restrooms?

**YEAP!** Most guys tend to avoid using urinals adjacent to occupied urinals! Might seem like a weird rule to some, but guys do this!

But not just urinals in guy's restroom... We notice the same **UNSPOKEN RULE** on trains as well. We tend to avoid sitting next to another passenger and always opt to sit away from each other when possible.

![meme](https://qph.cf2.quoracdn.net/main-qimg-1441a7a24648221a45608cd60ca45467-lq)

*Source links for context*

[Quora](https://www.quora.com/Is-there-a-pattern-as-to-how-guys-choose-urinals-when-entering-a-public-toilet-or-is-it-completely-random)

[Linkedin article](https://www.linkedin.com/pulse/20140725150107-6610781-the-9-unwritten-rules-of-men-s-bathroom-decorum/)


## 実行方法

以下のコマンドでコンパイルできます。
```
$ gcc main_{OS_NAME}.c
```

その後、以下で実行できます。
```
$ ./a.out
```

そうするとまずはルール説明になります。
```console
    Welcome to THE UNSPOKEN RULE
    Players take turns ...
```
ルール表示の後に、ゲームボードが表示されて入力待ちの状態になります。
```console
            The Unspoken Rule

 ---------------------------------------
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
 ---------------------------------------
    Player 1's turn!
    （入力）
```
## １ターンの流れ

1.  `0` ~ `9` 間の数値を入力して `Enter`を押す
2. 入力された場所が `X` になり、この場所と隣接している場所は他のプレイヤーには入力不可能になる
3. 最後に使える場所がなくなったプレイヤーが **UNSPOKEN RULE**を守りきれなかったと見なされ、`LOSER`！

** 複数人からじゃんけんで順番決めてするか、二人勝負でもOK！

** 必勝法はあるか？

## 課題１から変えたところ
一見課題１とは全く違うコードに見えるが、今日習った`文字列`の扱い方や`getchar()`を使って入力を取り込むというところをここで実装しました！
