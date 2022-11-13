#ifndef MINISHELL_H
# define MINISHELL_H
# include "../PRINTF/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <curses.h>
# include <signal.h>
# include <termios.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h> 

# define NAME_SHELL "\033[0;36m\033[1m42minishell ▸ \x1b[0m"
# define DIVISOR_SHELL " ▸ "
# define HOME_SHELL " ~ "
# define FILE_HISTORY "/.42minishell_history"
# define FILE_MATRIX "irina"
# define RED "\x1b[31m"
# define COLOR_RES  "\x1b[0m"
# define ERROR_DOUBLE_QUOTE "Mistake : unclosed double quotes"
# define ERROR_SING_QUOTE "Mistake : unclosed single quotes"
# define ERROR_BACKSLASH "Mistake : find the '\\'"
# define ERROR_OPEN_BRACKETS "Mistake : find open brackets exstra"
# define ERROR_CLOSE_BRACKETS "Mistake : find close brackets exstra"
# define ERROR_OP_LOGIC "Syntax error near unexpected token"
# define ERROR_FILE "No such file or directory"
# define INPUT 60
# define OUTPUT 62

typedef struct s_token
{
	int				res;
	int				priority;
	int				dup;
	int				stdinput;
	int				stdoutput;
	char			**value;
	char			*command;
	char			*name_file;
	bool			or;
	bool			and;
	bool			pipe;
	bool			input;
	bool			output;
	bool			append;
	bool			heredoc;
	struct s_main	*main;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_main
{
	char		**copy_env;
	char		**export_env;
	char		*copy_line;
	int			open_brackets;
	int			close_brackets;
	int			fd_matrix;
	int			dub_quotes;
	int			sin_quotes;
	int			count;
	bool		op_logic;
	bool		error;
	bool		redirections;
	bool		sub_shell;
	bool		expand;
	t_token		*token;
}	t_main;

// DIR Utils
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strchr(const char *s, int c);
int			ft_strchr_until(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_lstsize(t_token *lst_or);
int			ft_lstsize_this(t_token *lst_or);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_searchstrchr(char const *str, char **array);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char *charset);
char		**ft_split_original(char const *s, char c);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_token **lst, t_token *new);
void		ft_lstcopy(t_token **lst, t_token *new);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strtrim(char const *s1, char const *set);
t_token		*ft_lstnew(void *content, t_main *main);
size_t		ft_strlen(char *s);
size_t		ft_matrixlen(char **s);
int			ft_find_in_env(char **matrix, char *str);
int			ft_find_in_exp(char **matrix, char *str);
char		**ft_get_next_line(t_main *main);
char		*ft_clear_brackets(char *str);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strclear(char *str, char del);

// free.c
void		ft_free_matrix(char **matrix);

// init_envp.c
char		**ft_init_envp(char **envp);
char		**ft_init_set(char	**envp);

// prompt.c
int			ft_prompt(char **envp, t_main *main);
void		ft_sig_handel(int signal);

// history.c
void		ft_add_history(char *line, char **envp);

// DIR syntax_check
int			ft_check_single_quote(char *line, t_main *main, int i);
int			ft_check_double_quote(char *line, t_main *main, int i);
char		*ft_expand_dollar(char *line, t_main *main);
char		*ft_expand_heredoc(char *line, t_main *main);
void		ft_check_syntax(char *line, t_main *main);
void		ft_check_redirection(char *line, t_main *main);
char		*ft_delete_brackets(char *line);

// DIR Execute
void		ft_execute_command(char *line, t_main *main);
void		ft_execute_dollar(t_token *token);
void		ft_store_matrix(t_token *token, t_main *main);
t_token		*ft_execute_enviroment(t_token *token, char *var_add);
t_token		*ft_execute_exeve(t_token *token, t_main *main);
int			ft_check_envi(char *line);
//// DIR EXECVE
void		ft_execve_or(t_token *token);
void		ft_execve_and(t_token *token);
t_token		*ft_priority(t_token *token, int lvl, t_main *main);

// DIR Parsing
char		*ft_find_path(char *cmd, t_main *main);
char		*ft_find_token(char *line, t_main *main);
void		ft_parsing(char *line, t_main *main);
void		ft_set_op_logic(char *line, t_token *token);
void		ft_set_values(char **line, t_main *main);
void		ft_set_priority(char *line, t_main *main, int brack);
void		ft_set_redirections(t_token *token);
t_token		*ft_return_head(t_token *list);
void		ft_set_info(char **tmp, t_main *main, char *copy_line, int count);

// DIR Built_in
int			ft_check_builtin(t_token *token);
char		*ft_clear_value(char *str);
void		ft_check_echo(t_token *token);
void		ft_export(t_token *token, t_main *main);
void		ft_cd(t_token *token, t_main *main);
void		ft_pwd(void);
void		ft_env(t_token *token);
void		ft_unset(t_token *token, t_main *main);
void		ft_exit(t_token *token);
t_token		*ft_execute_builtin(t_token *s_token, t_main *main);
t_token		*ft_end_execute_(t_token *token, int fd_pipe[2], t_main *main);

extern void	rl_replace_line(const char *text, int clear_undo);

//DIR Redirection
void		ft_heredoc(t_token *token, t_main *main);
char		*ft_find_name_file(char *str);
int			ft_write_fd(int fd, char *limiter, t_main *main);
void		ft_input_redirect(t_token *token, t_main *main);
void		ft_output_redirect(t_token *token, t_main *main);
void		ft_delete_redirection(t_token *token);
t_token		*ft_redirections(t_token *token, t_main *main);
void		ft_execute_multi_redir(t_token *token, t_main *main);
void		ft_single_redir(t_token *token, t_main *main);
char		*ft_create_line(t_token *token);
char		**ft_clear_matrix(char **matrix);
int			ft_search_redir(t_token *token, char *redir);
int			ft_count_redirection(t_token *token);
void		ft_change_name_file(t_main *main, t_token *token, char redir);

// temporary
void		ft_print_lst(t_token *a);
void		ft_qualcosa(t_token *token, t_main *main);
t_token		*ft_execute_exeve(t_token *token, t_main *main);

#endif