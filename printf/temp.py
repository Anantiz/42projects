str = r"ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c"

str=str.replace('\n','').replace("\\",'').replace(' ','').replace('\t', '')

str=str.replace("\\",'')
strs = str.split('.c')
end = ".c \\\n".join(strs)


print(end)