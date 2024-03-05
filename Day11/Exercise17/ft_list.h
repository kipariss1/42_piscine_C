#ifndef __FT_LIST__
#define __FT_LIST__

typedef struct s_list
{
  struct s_list *next;
  void *data;

} t_list;

#endif		// __FT_LIST__
