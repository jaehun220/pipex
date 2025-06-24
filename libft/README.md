# Libft

📚 42 커리큘럼의 첫 번째 과제 — 나만의 C 라이브러리 만들기
<br>

## 📖 개요

`Libft`는 C 언어에서 자주 사용되는 표준 라이브러리 함수들을 직접 구현하여  
자신만의 라이브러리를 만드는 프로젝트입니다.  
이 과제를 통해 메모리, 문자열, 리스트 등 핵심적인 로우레벨 기능들을 익히고  
추후 모든 42 과제에서 재사용 가능한 기반 코드를 구축하게 됩니다.
<br>

## ⚙️ 과제 정보

- 언어: **C**
- 필수 규칙: **Norminette** 스타일 준수
- 허용 함수: 과제에서 명시한 외부 함수만 사용 가능
- 제출 대상: `libft.a`, `libft.h`, `ft_*.c`, `Makefile`
- 필수 컴파일 옵션: `-Wall -Wextra -Werror`
- 라이브러리 생성 명령어: `ar rc libft.a ...`
<br>

## 🧩 필수 구현 함수

### Part 1 — Libc 함수 재구현

다음 함수들은 `libc`의 동작을 따라 `ft_` 접두어를 붙여 직접 구현합니다.  
함수 원형은 `<string.h>`나 `<ctype.h>` 등의 매뉴얼을 기준으로 합니다.

- 문자 판별: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- 문자열 및 메모리: `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- 문자열 복사 및 연결: `ft_strlcpy`, `ft_strlcat`
- 대소문자 변환: `ft_toupper`, `ft_tolower`
- 문자열 탐색: `ft_strchr`, `ft_strrchr`
- 문자열 비교 및 검색: `ft_strncmp`, `ft_strnstr`
- 메모리 탐색 및 비교: `ft_memchr`, `ft_memcmp`
- 문자열 to 정수 변환: `ft_atoi`
- 동적 메모리: `ft_calloc`, `ft_strdup`

> 주의: `restrict` 키워드는 사용하지 않으며 `-std=c99` 플래그도 금지입니다.
<br>

### Part 2 — 추가 함수

표준 라이브러리에는 없지만 유용하게 사용되는 함수들을 직접 구현합니다.

- 문자열 처리:  
  `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`

- 숫자 및 문자 처리:  
  `ft_itoa`, `ft_strmapi`, `ft_striteri`

- 파일 디스크립터 출력:  
  `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
<br>

## 🏅 보너스 파트 (선택 사항)

보너스는 필수 파트를 **완벽하게 구현한 경우**에만 평가됩니다.

### 연결 리스트 함수

다음 구조체를 기준으로 단일 연결 리스트를 조작하는 함수들을 구현합니다.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```
<br>

- 노드 생성 및 조작:
  `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
- 리스트 정보 확인:
  `ft_lstsize`, `ft_lstlast`
- 메모리 해제:
  `ft_lstdelone`, `ft_lstclear`
- 순회 및 매핑:
  `ft_lstiter`, `ft_lstmap`
