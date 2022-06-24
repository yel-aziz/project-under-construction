/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:45 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/13 23:19:36 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

// t_env *__init__env(char **envp)
// {
//     t_env *lst;
//     int i = 0;
    
//     while (envp[i])
//     {
//         ft_lst_add_back(ft_lst_new(envp[i]));
//     }
//     return lst;
// }

// void    ft_env(void)
// {
//     char *env;
//     char **sub_env;
//     int i;

//     i = 0;
// 	env = "TMPDIR,SHELL,HOME,SSH_AUTH_SOCK,Apple_PubSub_Socket_Render,LOGNAME,\
//     PATH,XPC_SERVICE_NAME,COMMAND_MODE,USER,SECURITYSESSIONID,XPC_FLAGS,\
//     __CF_USER_TEXT_ENCODING,ORIGINAL_XDG_CURRENT_DESKTOP,SHLVL,\
//     PWD,OLDPWD,ZSH,PAGER,LESS,LSCOLORS,HOMEBREW_NO_AUTO_UPDATE,\
//     TERM_PROGRAM,TERM_PROGRAM_VERSION,LANG,COLORTERM,\
//     VSCODE_GIT_IPC_HANDLE,GIT_ASKPASS,VSCODE_GIT_ASKPASS_NODE,\
//     VSCODE_GIT_ASKPASS_EXTRA_ARGS,VSCODE_GIT_ASKPASS_MAIN,TERM";
//     sub_env = ft_split(env, ',');
//     while (i < 32)
//     {   sub_env[i] = ft_strtrim(sub_env[i], " ");
//         printf("%s=%s\n", sub_env[i], getenv(sub_env[i]));
//         i++;
//     }
//     printf("_=%s\n", getenv("_"));
//     free(sub_env);
// }