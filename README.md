🛡️ Batalha Naval — MateCheck

Atualizado: 21/02

Visão geral

Projeto acadêmico e demonstrativo que implementa funcionalidades progressivas do jogo Batalha Naval em C. O repositório apresenta três níveis de complexidade (Novato, Aventureiro e Mestre) e tem foco em manipulação de matrizes (arrays 2D), estruturas de repetição, modularização e documentação de código — ideal para incluir em um portfólio técnico.

Destaques (o que o projeto demonstra)

Representação de tabuleiros com arrays 2D.

Posicionamento de navios (vertical, horizontal e diagonal).

Geração e visualização de padrões matriciais (cone, cruz, octaedro).

Uso de loops aninhados, modularização em funções e boas práticas de código.

Documentação clara e instruções de compilação para avaliadores e recrutadores.

Estrutura do repositório (sugerida)
batalha-naval-matecheck/
├── README.md
├── Makefile
├── LICENSE
├── src/
│   ├── novato.c
│   ├── aventureiro.c
│   └── mestre.c
├── examples/
│   └── output_examples.txt
└── docs/
    └── diagrams.png   (opcional)

Níveis implementados
Nível Novato

Tabuleiro simples (matriz).

Posicionamento de 2 navios: 1 vertical e 1 horizontal.

Impressão das coordenadas e do tabuleiro.

Nível Aventureiro

Tabuleiro 10×10.

Posicionamento de 4 navios, incluindo dois em diagonal.

Impressão do tabuleiro completo (0 = vazio, 3 = navio).

Nível Mestre

Implementação de padrões de habilidade: cone, cruz, octaedro.

Padrões sobrepostos ao tabuleiro 10×10, com 0/1 indicando áreas afetadas.

Uso de loops aninhados e modularização; versão com recursão opcional.
