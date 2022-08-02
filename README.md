# Karaoke Decompressor - Aegisub

O Karaoke-Decompressor é um script capaz de "descomprimir" várias linhas de karaoke criadas pelo [Aegisub](https://github.com/Ristellise/AegisubDC), as linhas resultantes das "descompressão" variam conforme o modo escolhido.

## Modo Simples

As linhas de karaoke são totalmente “descomprimidas” e os estilos presentes no karaoke são salvaguardados, como é possivel ver no exemplo abaixo apresentado tanto o nome do estilo como a cor secundária foram preservados.

```bash

Estilo:

Style: OP_JP,FOT-TsukuARdGothic Std E,85,&H00FFFFFF,&H00838385,&H00000000,&H00000000,0,0,0,0,100,100,0,0,1,3,0,8,10,10,20,1

Linha incial:

Dialogue: 0,0:00:53.03,0:00:57.12,OP_JP,,0,0,0,,{\k53}{\k33}ho{\k30}n{\k22}to {\k52}wa {\k16}sa{\k47}so{\k24}tte {\k11}ho{\k28}shi{\k21}i {\k21}na{\k20}n{\k31}te

Linhas resultantes:

Dialogue: 0,0:00:53.03,0:00:53.56,OP_JP,,0,0,0,,{\c&H00838385}honto wa sasotte hoshii nante
Dialogue: 0,0:00:53.56,0:00:53.89,OP_JP,,0,0,0,,ho{\c&H00838385}nto wa sasotte hoshii nante
Dialogue: 0,0:00:53.89,0:00:54.19,OP_JP,,0,0,0,,hon{\c&H00838385}to wa sasotte hoshii nante
Dialogue: 0,0:00:54.19,0:00:54.41,OP_JP,,0,0,0,,honto {\c&H00838385}wa sasotte hoshii nante
Dialogue: 0,0:00:54.41,0:00:54.93,OP_JP,,0,0,0,,honto wa {\c&H00838385}sasotte hoshii nante
Dialogue: 0,0:00:54.93,0:00:55.09,OP_JP,,0,0,0,,honto wa sa{\c&H00838385}sotte hoshii nante
Dialogue: 0,0:00:55.09,0:00:55.56,OP_JP,,0,0,0,,honto wa saso{\c&H00838385}tte hoshii nante
Dialogue: 0,0:00:55.56,0:00:55.80,OP_JP,,0,0,0,,honto wa sasotte {\c&H00838385}hoshii nante
Dialogue: 0,0:00:55.80,0:00:55.91,OP_JP,,0,0,0,,honto wa sasotte ho{\c&H00838385}shii nante
Dialogue: 0,0:00:55.91,0:00:56.19,OP_JP,,0,0,0,,honto wa sasotte hoshi{\c&H00838385}i nante
Dialogue: 0,0:00:56.19,0:00:56.40,OP_JP,,0,0,0,,honto wa sasotte hoshii {\c&H00838385}nante
Dialogue: 0,0:00:56.40,0:00:56.61,OP_JP,,0,0,0,,honto wa sasotte hoshii na{\c&H00838385}nte
Dialogue: 0,0:00:56.61,0:00:56.81,OP_JP,,0,0,0,,honto wa sasotte hoshii nan{\c&H00838385}te
Dialogue: 0,0:00:56.81,0:00:57.12,OP_JP,,0,0,0,,honto wa sasotte hoshii nante
```

## Modo Avançado

Este modo é praticamente igual ao anterior, muda o facto de podermos mudar o estilo de uma linha a meio do karaoke, ou seja, podemos trocar cores, fontes, etc... em plena execução de um karaoke.
Neste exemplo as linhas resultante são identicas às do exemplo anterior, contudo reprarem que existem uma mudança de estilo num determinado momento que é escolhido pelo utilizador.

```bash
Estilos:

Style: OP_JP,FOT-TsukuARdGothic Std E,85,&H00FFFFFF,&H00838385,&H00000000,&H00000000,0,0,0,0,100,100,0,0,1,3,0,8,10,10,20,1
Style: END_JP,FOT-TsukuARdGothic Std E,85,&H00FFFFFF,&H0090938F,&H00000000,&H00000000,0,0,0,0,100,100,0,0,1,3,0,8,10,10,20,1

Linha inicial:

Dialogue: 0,0:00:53.03,0:00:57.12,OP_JP,,0,0,0,,{\k53}{\k33}ho{\k30}n{\k22}to {\k52}wa {\k16}sa{\k47}so{\k24}tte {\k11}ho{\k28}shi{\k21}i {\k21}na{\k20}n{\k31}te

Tempo da mudança de estilo: 

0:00:55.00

Linhas resultantes:

Dialogue: 0,0:00:53.03,0:00:53.56,OP_JP,,0,0,0,,{\c&H00838385}honto wa sasotte hoshii nante
Dialogue: 0,0:00:53.56,0:00:53.89,OP_JP,,0,0,0,,ho{\c&H00838385}nto wa sasotte hoshii nante
Dialogue: 0,0:00:53.89,0:00:54.19,OP_JP,,0,0,0,,hon{\c&H00838385}to wa sasotte hoshii nante
Dialogue: 0,0:00:54.19,0:00:54.41,OP_JP,,0,0,0,,honto {\c&H00838385}wa sasotte hoshii nante
Dialogue: 0,0:00:54.41,0:00:54.93,OP_JP,,0,0,0,,honto wa {\c&H00838385}sasotte hoshii nante
Dialogue: 0,0:00:54.93,0:00:55.00,OP_JP,,0,0,0,,honto wa sa{\c&H00838385}sotte hoshii nante
Dialogue: 0,0:00:55.00,0:00:55.09,END_JP,,0,0,0,,honto wa sa{\c&H0090938F}sotte hoshii nante
Dialogue: 0,0:00:55.09,0:00:55.56,END_JP,,0,0,0,,honto wa saso{\c&H0090938F}tte hoshii nante
Dialogue: 0,0:00:55.56,0:00:55.80,END_JP,,0,0,0,,honto wa sasotte {\c&H0090938F}hoshii nante
Dialogue: 0,0:00:55.80,0:00:55.91,END_JP,,0,0,0,,honto wa sasotte ho{\c&H0090938F}shii nante
Dialogue: 0,0:00:55.91,0:00:56.19,END_JP,,0,0,0,,honto wa sasotte hoshi{\c&H0090938F}i nante
Dialogue: 0,0:00:56.19,0:00:56.40,END_JP,,0,0,0,,honto wa sasotte hoshii {\c&H0090938F}nante
Dialogue: 0,0:00:56.40,0:00:56.61,END_JP,,0,0,0,,honto wa sasotte hoshii na{\c&H0090938F}nte
Dialogue: 0,0:00:56.61,0:00:56.81,END_JP,,0,0,0,,honto wa sasotte hoshii nan{\c&H0090938F}te
Dialogue: 0,0:00:56.81,0:00:57.12,END_JP,,0,0,0,,honto wa sasotte hoshii nante{\c&H0090938F}
Dialogue: 0,0:00:57.12,0:00:57.12,END_JP,,0,0,0,,honto wa sasotte hoshii nante
```
## Demos

Para perceber melhor a utilização do script aconselho a visualização de duas demos, cada uma relativa a um modo diferente.

 - [Modo Simples]
 - [Modo Avançado]

## Notas de utilização

- Ao inserir os tempos no Modo Avançado, estes devem estar por ordem.
- Não é possível colocar um tempo de mudança que esteja fora do karaoke, ou seja, no exemplo anterior não seria possível colocar um tempo igual a 0:00:30.00.
- Têm de colocar todos os dados relativos aos estilos que serão utilizados no karaoke.
