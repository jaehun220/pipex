# Pipex

## 📌 요약
이 프로젝트는 여러분이 이미 알고 있는 **UNIX 파이프(pipe)** 메커니즘을 직접 구현해 보면서, 그 동작 원리를 깊이 탐구하는 것을 목표로 합니다.

---

## 📂 목차
1. [서문 (Foreword)](#서문-foreword)  
2. [공통 규칙 (Common Instructions)](#공통-규칙-common-instructions)  
3. [필수 파트 (Mandatory part)](#필수-파트-mandatory-part)  
4. [예제 (Examples)](#예제-examples)  
5. [요구 사항 (Requirements)](#요구-사항-requirements)  
6. [보너스 파트 (Bonus part)](#보너스-파트-bonus-part)  
7. [제출 및 동료 평가 (Submission and peer-evaluation)](#제출-및-동료-평가-submission-and-peer-evaluation)  

---

## 📝 서문 (Foreword)
> Cristina: "가서 살사 춤을 춰 보세요! :)"

---

## 📜 공통 규칙 (Common Instructions)
- 프로젝트는 **C 언어**로 작성해야 합니다.
- **Norm 규칙**을 준수해야 하며, 보너스 코드/함수도 Norm 검사에 포함됩니다.  
  Norm 에러가 발생하면 점수는 **0점**입니다.
- 프로그램은 예기치 않게 종료되면 안 됩니다. (Segmentation Fault, Bus Error, Double Free 등)  
  정의되지 않은 동작을 제외하고, 이런 문제가 발생하면 0점 처리됩니다.
- 동적 할당한 메모리는 필요 시 반드시 해제해야 하며, 메모리 누수는 허용되지 않습니다.
- Makefile은 `-Wall -Wextra -Werror` 옵션을 포함해 `cc`로 컴파일해야 하며, **불필요한 재링크가 없어야 합니다.**
- Makefile에는 최소한 다음 규칙이 포함되어야 합니다:  
  `$(NAME)`, `all`, `clean`, `fclean`, `re`
- 보너스를 제출하려면 Makefile에 `bonus` 규칙을 추가하고,  
  보너스 파일은 `_bonus.{c/h}` 형식으로 작성해야 합니다.
- libft 사용 가능 시, 소스와 Makefile을 `libft` 폴더에 포함해야 합니다.
- 제출 전 **테스트 프로그램 제작 권장** (방어 평가 시 유용)

---

## 🛠 필수 파트 (Mandatory part)

**프로그램 이름:** `pipex`  
**제출 파일:** `Makefile`, `*.h`, `*.c`  
**Makefile 규칙:** `NAME`, `all`, `clean`, `fclean`, `re`  
**실행 인자:**  `file1 cmd1 cmd2 file2`

**사용 가능 함수:**  
`open, close, read, write,
malloc, free, perror, strerror, access,
dup, dup2, execve, exit, fork, pipe,
unlink, wait, waitpid`

(`ft_printf` 또는 직접 구현한 동등 함수 사용 가능)  

---

### 🎯 목표
다음 명령과 동일하게 동작하는 프로그램 작성:
```bash
./pipex file1 cmd1 cmd2 file2
동작은 다음 셸 명령과 동일해야 합니다:
< file1 cmd1 | cmd2 > file2

./pipex infile "ls -l" "wc -l" outfile
# 동일 동작: < infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
# 동일 동작: < infile grep a1 | wc -w > outfile
```
### 📋 요구 사항 (Requirements)
Makefile은 불필요한 재링크를 하지 않아야 합니다.

프로그램은 절대 예기치 않게 종료되어서는 안 됩니다.

메모리 누수가 없어야 합니다.

오류 처리 방식은 실제 셸 명령 < file1 cmd1 | cmd2 > file2와 동일하게 구현.

### 보너스 없음

### 📦 제출 및 동료 평가 (Submission and peer-evaluation)
과제는 지정된 Git 저장소에 제출

방어 평가 시 저장소 내용만 평가

파일 이름과 규칙을 반드시 확인
