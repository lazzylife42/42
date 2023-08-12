#include "get_next_line.h"
#include <stdio.h>

/* This function reads lines from the specified file descriptor (fd). */
char *get_next_line(int fd)
{
    /* A static buffer to store data between function calls. */
    static char *buff;
    char *line;

    /* Check for invalid file descriptor or negative buffer size. */
    if ((fd < 0) || (BUFFER_SIZE <= 0))
        return (NULL);

    /* Read data from the file descriptor and store it in the buffer. */
    buff = gnl_read(fd, buff);
    if (!buff)
        return (NULL);

    /* Extract a line from the buffer. */
    line = gnl_get_line(buff);

    /* Remove the extracted line from the buffer. */
    buff = gnl_remove_old_line(buff);

    return (line);
}

/* This function finds the index of the first newline character in the buffer. */
ssize_t find_newline_index(char *buff)
{
    ssize_t i = 0;

    /* Iterate through the buffer to find a newline character. */
    while (buff[i])
    {
        if (buff[i] == '\n')
            return (i);
        i++;
    }
    return (-1); /* No newline character found. */
}

/* This function reads data from the file descriptor and appends it to the existing buffer. */
char *gnl_read(int fd, char *res)
{
    ssize_t bytes_readed;
    char *buff;

    /* If res is NULL, initialize it with an empty string. */
    if (!res)
        res = (char *)ft_calloc(1, sizeof(char));

    /* Allocate memory for the buffer. */
    buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!res || !buff)
        return (NULL);

    bytes_readed = 1;

    /* Read data in chunks of BUFFER_SIZE. */
    while (bytes_readed > 0)
    {
        bytes_readed = read(fd, buff, BUFFER_SIZE);

        /* Handle read error. */
        if (bytes_readed == -1)
        {
            free(buff);
            free(res);
            return (NULL);
        }

        /* Null-terminate the buffer. */
        buff[bytes_readed] = 0;

        /* Concatenate the buffer content with the existing result. */
        res = ft_gnl_strjoin(res, buff);

        /* Break if a newline character is found. */
        if (find_newline_index(buff) != -1)
            break;
    }

    free(buff); /* Free the temporary buffer. */
    return (res);
}

/* This function extracts a line from the buffer. */
char *gnl_get_line(char *buff)
{
    int i;
    char *str;

    /* If the buffer is empty, return NULL. */
    if (!buff[0])
        return (NULL);

    /* Find the index of the newline character. */
    i = find_newline_index(buff);
    if (i == -1)
        i = ft_strlen(buff);

    /* Create a new string containing the extracted line. */
    str = ft_strndup(buff, i);
    if (!str)
        return (NULL);

    return (str);
}

/* This function removes the old line from the buffer. */
char *gnl_remove_old_line(char *buff)
{
    char *str;
    int i;
    int j;

    /* Handle NULL buffer by freeing it and returning NULL. */
    if (buff == NULL)
        return (ft_free_null(buff));

    /* Find the index of the newline character. */
    i = find_newline_index(buff);
    if (i == -1)
        return (ft_free_null(buff));

    /* Allocate memory for the new buffer. */
    str = (char *)ft_calloc(ft_strlen(buff) - i + 1, sizeof(char));
    if (!str)
        return (ft_free_null(buff));

    j = 0;

    /* Copy content after the newline character to the new buffer. */
    while (buff[++i])
        str[j++] = buff[i];

    str[j] = '\0';

    free(buff); /* Free the old buffer. */
    return (str);
}

/* The following are the implementation of the helper functions (ft_strlen, ft_calloc, ft_strndup, ft_gnl_strjoin, ft_free_null).
These functions are used within the main functions to manage memory and manipulate strings. */
