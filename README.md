![C](https://img.shields.io/badge/language-C-blue)

# Simulador de Retângulos (mundo 80x25)

Programa em C que permite **criar**, **mover** e **apagar** retângulos num “mundo” 2D com dimensões **80 (largura) x 25 (altura)**.  
Após cada operação válida, o mundo é desenhado no terminal e é aplicada **gravidade** (os retângulos “caem” até ficarem apoiados no chão ou noutro retângulo).  
Também é emitido um alerta quando existe **colisão lateral** (retângulos encostados lado a lado com sobreposição vertical).

---

## Funcionalidades

- **Create**: cria um retângulo nas coordenadas indicadas, se estiver dentro dos limites e sem colisões.
- **Move left / right**: move horizontalmente um retângulo identificado por um ponto que esteja dentro dele.
- **Delete**: remove um retângulo identificado por um ponto que esteja dentro dele.
- **Gravidade automática**: após criar/mover/apagar, os retângulos descem enquanto for possível.
- **Renderização em ASCII**:
  - Bordas: `x`
  - Interior: `+`
  - Centro: dígito com o **ID** do retângulo
- **Alerta de colisão lateral**: imprime mensagem quando dois retângulos ficam encostados lateralmente com interseção vertical.

---

## Coordenadas e limites

- O mundo tem:
  - `W_MAX = 80` (colunas)
  - `H_MAX = 25` (linhas)
- As coordenadas são **1-based**:
  - `(1,1)` é o canto **inferior esquerdo**
- Um retângulo é definido por:
  - `(x,y)` = canto inferior esquerdo
  - `w` = largura
  - `h` = altura

---
