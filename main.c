
#include "ft_printf.h"

int ft_printf(const char *fm, ...)
{
    size_t ret;
    va_list args;
    
    ret = 0;
    va_start(args, fm);
    if (!*fm)
        return (0);
    ret = ft_check_fm(&args, fm, ret);
    va_end(args);
    if (ret > INT_MAX)
        return(-1);
        else
    return((int)ret);
}

int     ft_if_percent(va_list *args, const char **fm, t_print **list, size_t *ret)
{
    if (*(*fm) == '\0')
            return (1);
    else if (*(*fm) == '%')
    {
        write(1,"%", 1);
        (*ret)++;
    //    (*fm)++;
    }
    else
    {
        *list = ft_new_list(*list);
        *fm = ft_get_format(*list, *fm);
        *ret = go_push_it(*list, args, *ret);
    }
    return (0);
}
 

size_t  ft_check_fm(va_list *args, const char *fm, size_t ret)
{
    t_print *list;
    
    list = NULL;
    while(*fm)
    {
        while(*fm && *fm != '%')
        {
            write(1, fm++, 1);
            ret++;
        }
        if (*fm && *fm++ == '%')
        {
            if (ft_if_percent(args, &fm, &list, &ret))
                return (0);
        }
        if (*fm)
            fm++;
    }
    return(ret);
}

void ft_print_num_zero(t_print *list, size_t *ret)
{
    while((list->width)--)
    {
        ft_putchar(' ');
        (*ret)++;
    }
}

void ft_print_arg(t_print *list, size_t *ret)
{
    (*(list->buf) == '0' && list->conversion == 'p' && list->dot && !(list->precision)) ?
    (*list->buf = '\0') : 0;
    (NUM(list->conversion) || list->conversion == 'p') ?
    ft_check_prefix(list) : 0;
    (NUM(list->conversion) || list->conversion == 'p') ?
    0 : (list->precision = 0);
    if (UOCT(list->conversion))
        list->len_p = (list->precision > ft_strlen(list->buf) + ft_strlen(list->prefix)) ?
        (list->precision - ft_strlen(list->buf) -
         ft_strlen(list->prefix)) : 0;
    else
        list->len_p = (list->precision > ft_strlen(list->buf) ) ?
        (list->precision - ft_strlen(list->buf)) : 0;
    (list->len_w) = (list->width > ft_strlen(list->buf)
                     + list->len_p + ft_strlen(list->prefix)) ?
    (list->width - ft_strlen(list->buf)
     - list->len_p - ft_strlen(list->prefix)) : 0;
    *ret = MINUS(list->flag) ? ft_print_left(list, *ret) :
    ft_print_right(list, *ret);
}

size_t go_push_it(t_print *list, va_list *args, size_t ret)
{
   ft_get_arg(list, args);
    if (*(list->buf) == '0' && (NUM(list->conversion)) && list->dot && !(list->precision) && list->width)
        ft_print_num_zero(list, &ret);
  else if (*(list->buf) == '0' && (NUM(list->conversion)) && list->dot && !(list->precision) && !list->width)
      ;
      else
          ft_print_arg(list, &ret);
    return(ret);
}

size_t ft_print_left(t_print *list, size_t ret)
{
    ft_putstr(list->prefix);
    ret += ft_strlen(list->prefix);
    ret += list->len_p;
    while((list->len_p)--)
        ft_putchar('0');
        if (*list->buf == '0' && SYMB(list->conversion))
    {
        ret++;
        ft_putchar('\0');
    }
    else
    {
        ft_putstr(list->buf);
        ret += ft_strlen(list->buf);
      }
        ret += list->len_w;
    while((list->len_w)--)
        ft_putchar(' ');
     return(ret);
}

void ft_print_right_post(t_print *list, size_t *ret)
{
ft_putstr(list->prefix);
(*ret) += ft_strlen(list->prefix);
(*ret) += list->len_w;
while((list->len_w)--)
ft_putchar('0');
if (*list->buf == '0' && SYMB(list->conversion))
{
    (*ret)++;
    ft_putchar('\0');
}
else
{
    ft_putstr(list->buf);
    (*ret) += ft_strlen(list->buf);
}
}

size_t ft_print_right(t_print *list, size_t ret)
{
    if ((!ZERO(list->flag)) || (ZERO(list->flag) && (list->precision)))
    {
        ret += list->len_w;
        while((list->len_w)--)
            ft_putchar(' ');
        ft_putstr(list->prefix);
        ret += ft_strlen(list->prefix);
        ret += list->len_p;
        while((list->len_p)--)
            ft_putchar('0');
        if (*list->buf == '0' && SYMB(list->conversion))
        {
            ret++;
            ft_putchar('\0');
        }
        else
        {
            ft_putstr(list->buf);
           ret += ft_strlen(list->buf);
       }
    }
          else
              ft_print_right_post(list, &ret);
    return(ret);
}

void ft_get_arg(t_print *list, va_list *args)
{
    if (DECIMAL(list->conversion))
        ft_get_digit(list, args);
    else if(UNSIGN(list->conversion))
        ft_get_unsigned(list, args);
   else if (SYMB(list->conversion) || STRING(list->conversion))
       ft_get_char(list, args);
}

void ft_check_prefix(t_print *list)
{
    if (DECIMAL(list->conversion))
    {
        if (list->sign == 1)
            *(list->prefix) = '-';
        else if (PLUS(list->flag))
            *(list->prefix) = '+';
        else if (SPACE(list->flag))
            *(list->prefix) = ' ';
    }
    else if (UOCT(list->conversion) && SHARP(list->flag)
            &&  *list->buf != '0')
             *(list->prefix) = '0';
    else if (UHEX(list->conversion) && SHARP(list->flag)
             &&  *list->buf != '0')
        list->prefix = (list->conversion == 'x') ?
        ft_strjoin(list->prefix,"0x") : ft_strjoin(list->prefix,"0X");
    else if (list->conversion == 'p')
        list->prefix = ft_strjoin(list->prefix,"0x");
    return ;
}

void        f(size_t value, size_t base, char *str, size_t *i, int upper)
{
    char    *tmp;
    
    tmp = (upper == 1) ?  "0123456789ABCDEF" : "0123456789abcdef";
    if (value >= base)
        f(value / base, base, str, i, upper);
    str[(*i)++] = tmp[(value % base)];
}

char        *ft_itoa_base(ssize_t value, size_t base, int upper)
{
    size_t        i;
    char    *str;
    
    i = 0;
    if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
        return (0);
    f(value, base, str, &i, upper);
    str[i] = '\0';
    return (str);
}

void ft_get_char(t_print *list, va_list *args)
{
    char c;
    char *s;
    wchar_t *wchar;
    
    if (SYMB(list->conversion))
    {
        if (!(c = (char)va_arg(*args, int)))
            list->buf = ft_strdup("0");
        else
        {
            list->buf = ft_strnew(1);
            (*list->buf) = c;
        }
    }
    else if (list->conversion == 's')
    {
        list->buf = ((s = va_arg(*args, char*)) == NULL) ?
        ft_push_char(list, "(null)") : ft_push_char(list, s);
    }
    else if (list->conversion == 'S' || (list->conversion == 's' &&
                                         (list->l % 2)))
    {
        list->buf = ((wchar = va_arg(*args, wchar_t*)) == NULL) ?
        ft_strdup("(null)") : ft_push_wchar(wchar, list);
    }
}

char *ft_push_char(t_print *list, char *s)
{
    char *str;
    char *tmp;
    size_t len;
    
    tmp = NULL;
    len = ((list->precision < ft_strlen(s)) && list->dot) ?
    list->precision : ft_strlen(s);
    tmp = ft_strnew(len);
    str = tmp;
    while(len-- && *s)
        *tmp++ = *s++;
    return(str);
}

char *ft_push_wchar(wchar_t *wchar, t_print *list)
{
    char *str;
    size_t len;
    
    len = 0;
    str = ft_strnew(0);
    while(*wchar)
    {
        len += ft_wchar_len(*wchar);
        if (list->precision >= len || !list->precision)
            str = ft_strjoin(str, ft_handle_wchar(*wchar));
            else
        break;
        wchar++;
    }
    return(str);
}

int ft_wchar_len(wchar_t wchar)
{
    if (wchar <= 0x007F)
        return(1);
    else if (wchar <= 0x07FF)
        return(2);
    else if (wchar <= 0xFFFF)
        return(3);
    else if (wchar <= 0x10FFFF)
        return(4);
    return (0);
}

char *ft_handle_wchar(wchar_t wchar)
{
    char *str;
    int len;
   
    len = ft_wchar_len(wchar);
    str = ft_strnew(len);
    if (len == 1)
        str[0] = wchar;
    else
        str[0] = (wchar >> (6 * (len - 1))) | (240 << (4 - len));
    while (--len)
    {
        str[len] = (wchar & 63) | 128;
        wchar >>= 6;
    }
    return(str);
}

void ft_get_unsigned(t_print *list, va_list *args)
{
    ssize_t unsign;
    
    if (USHORT(list->conversion) && (list->size == 'H'))
        unsign = (unsigned char)va_arg(*args, unsigned int);
    else if (USHORT(list->conversion) && (list->size == 'h'))
        unsign = (unsigned short)va_arg(*args, unsigned int);
    else if ((USHORT(list->conversion) && (list->size == 'l')) || ULONG(list->conversion))
        unsign = va_arg(*args, unsigned long);
    else if (USHORT(list->conversion) && (list->size == 'L'))
        unsign = va_arg(*args, unsigned long long);
    else if (USHORT(list->conversion) && (list->size == 'j'))
        unsign = va_arg(*args, uintmax_t);
    else if ((USHORT(list->conversion) && (list->size == 'z'))  || (list->conversion == 'p'))
        unsign = va_arg(*args, size_t);
    else
        unsign = va_arg(*args, unsigned int);
    if (UOCT(list->conversion))
        list->buf = ft_itoa_base(unsign, 8, 0);
    else if (UDECIMAL(list->conversion))
        list->buf = ft_itoa_base(unsign, 10, 0);
    else
        list->buf = (list->conversion == 'X') ?
        ft_itoa_base(unsign, 16, 1) : ft_itoa_base(unsign, 16, 0);
}


void ft_get_digit(t_print *list, va_list *args)
{
    ssize_t digit;
    
    if (LDECIMAL(list->conversion) && (list->size == 'H'))
        digit = (char)va_arg(*args, int);
    else if (LDECIMAL(list->conversion) && (list->size == 'h'))
        digit = (short)va_arg(*args, int);
    else if ((LDECIMAL(list->conversion) && list->l % 2) || list->conversion == 'D')
        digit = va_arg(*args, long);
    else if (LDECIMAL(list->conversion) && (list->size == 'L'))
        digit = va_arg(*args, long long);
    else if (LDECIMAL(list->conversion) && (list->size == 'j'))
        digit = va_arg(*args, intmax_t);
    else if (LDECIMAL(list->conversion) && (list->size == 'z'))
        digit = va_arg(*args, ssize_t);
    else
        digit = va_arg(*args, int);
    (digit < 0) ? list->sign = 1 : 0;
    digit = (digit < 0) ? (-digit) : digit;
    list->buf = ft_itoa_base(digit, 10, 0);
}

t_print *ft_new_list(t_print *list)
{
    if(!(list = (t_print*)ft_memalloc(sizeof(t_print))))
        return(NULL);
    (list)->prefix = ft_strnew(2);
    return(list);
}

const char *ft_get_format(t_print *list, const char *fm)
{
    while (*fm && ft_strchr("-+ #0.123456789lhzj", *fm))
    {
        while (FLAG(*fm))
            ft_get_flag(list, *(fm++));
        if ((*fm) >= '1' && (*fm) <= '9')
        {
            list->width = 0;
            while(ft_isdigit(*fm))
            list->width = (list->width * 10) + (*fm++) - '0';
        }
        if (*fm == '.')
        {
            list->dot = 1;
            list->precision = 0;
            while (ft_isdigit((*(++fm))))
                list->precision = (list->precision * 10) + (*fm) - '0';
        }
        while(*fm && ft_strchr("lhzj", *fm))
            ft_get_size(list, *(fm++));
    }
    ft_check_size(list);
    ft_check_converse(list, &fm);
    return(fm);
}

void ft_check_converse(t_print *list, const char **fm)
{
    if (**fm && CONVERSE(**fm))
        list->conversion = **fm;
    else if (*fm && !(CONVERSE(**fm)))
    {
        list->buf = ft_memalloc(2);
        *(list->buf) = **fm;
     }
}

void ft_check_size(t_print *list)
{
    if (list->z == 1)
        list->size = 'z';
    else if(list->j == 1)
        list->size = 'j';
    else if (list->l > 0)
    {
        if (((list->l) % 2) == 0)
            list->size = 'L';
        else
            list->size = 'l';
    }
    else if ((list->h) > 0)
    {
        if (((list->h) % 2) == 0)
            list->size = 'H';
        else
            list->size = 'h';
    }
}

void ft_get_flag(t_print *list, char fm)
{
    if (fm == '#')
        list->flag |= 0x01;
    else if (fm == '0')
        list->flag |= 0x01 << 1;
    else if (fm == '-')
        list->flag |= 0x01 << 2;
    else if (fm == '+')
        list->flag |= 0x01 << 3;
    else if (fm == ' ')
        list->flag |= 0x01 << 4;
}

void ft_get_size(t_print *list, char fm)
{
    if (fm == 'l')
        list->l++;
    else if (fm == 'h')
        list->h++;
    else if (fm == 'z')
        list->z = 1;
    else if (fm == 'j')
        list->j = 1;
}


#define ARG2 "%.1d"
#define ARG22 0

#define ARG3 "123%353- zhll..08h +#"
#define ARG33 8


#define ARG1 "\t|%012i|"
#define ARG11 -42

/*
int main(void)

{
    
    //ft_printf("|%-#13.10o\t|%-12#.10o|\t|%-13.10#o|\t|%-13.-9#o|\t\t", 25,25,25,25);
    
    //ft_printf("|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|", NULL,NULL,NULL,NULL);
   //ft_printf("|%S|\t|%S|\t|%C|\t|%S|",L"Wide sample string..",L"米",L'米',L"");

 //PRINTF("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|\t|%.C|\t|%.5C|", 0,0,0,0,0,0,0,0,0);
    int i;
    
    write(1, "[", 1);
    i = ft_printf(ARG1, ARG11);
    ft_printf("]\n(ft)[%d]\n", i);
//    i = ft_printf(ARG2, ARG22);
//    ft_printf("[%d]\n", i);
//    i = ft_printf(ARG3, ARG33);
//    ft_printf("[%d]\n", i);

    printf("\n[");
    i = printf(ARG1, ARG11);
    printf("]\n(pf)[%d]\n", i);
//    i = printf(ARG2, ARG22);
//    printf("[%d]\n", i);
//    i = printf(ARG3, ARG33);
//    printf("[%d]\n", i);
    

   return 0;
}

*/
