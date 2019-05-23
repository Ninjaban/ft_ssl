/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:45:35 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/18 13:15:54 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"

extern t_bool	ft_base64_encode(t_pchar string, t_pchar *out)
{
	const char base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	const uint8_t *data = (const uint8_t *)string;
	t_pchar	result;
	size_t	resultIndex = 0;
	size_t x;
	uint32_t n;
	size_t dataLength;
	size_t resultSize;
	int padCount;
	uint8_t n0, n1, n2, n3;

	x = 0;
	n = 0;
	dataLength = ft_strlen(string);
	resultSize = (dataLength * 4) / 3 + dataLength % 3;
	ft_putendl("test1");
	result = malloc(sizeof(char) * ((dataLength * 4) / 3 + dataLength % 3));
	ft_putendl("test2");
	padCount = dataLength % 3;
	/* increment over the length of the string, three characters at a time */
	while (x < dataLength) 
	{
    	/* these three 8-bit (ASCII) characters become one 24-bit number */
      	n = ((uint32_t)data[x]) << 16; //parenthesis needed, compiler depending on flags can do the shifting before conversion to uint32_t, resulting to 0
     
    	if((x+1) < dataLength)
        	n += ((uint32_t)data[x+1]) << 8;//parenthesis needed, compiler depending on flags can do the shifting before conversion to uint32_t, resulting to 0
		
    	if((x+2) < dataLength)
        	n += data[x+2];

    	/* this 24-bit number gets separated into four 6-bit numbers */
    	n0 = (uint8_t)(n >> 18) & 63;
      	n1 = (uint8_t)(n >> 12) & 63;
      	n2 = (uint8_t)(n >> 6) & 63;
      	n3 = (uint8_t)n & 63;
            
    	/*
    	* if we have one byte available, then its encoding is spread
    	* out over two characters
    	*/
    	if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
    		result[resultIndex++] = base64chars[n0];
    	if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
      		result[resultIndex++] = base64chars[n1];

    	/*
      	* if we have only two bytes available, then their encoding is
      	* spread out over three chars
      	*/
      	if((x+1) < dataLength)
      	{ 
      	   if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
       		result[resultIndex++] = base64chars[n2];
    	}

      	/*
       	* if we have all three bytes available, then their encoding is spread
       	* out over four characters
       	*/
      	if((x+2) < dataLength)
      	{
      	   if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
      		   result[resultIndex++] = base64chars[n3];
      	}
		x = x + 3;
   	}

	/*
    * create and add padding that is required if we did not have a multiple of 3
    * number of characters available
    */
   	if (padCount > 0) 
	{ 
      while (padCount < 3) 
    	{ 
        	if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
        		result[resultIndex++] = '=';
			padCount++;
		} 
	}
	if(resultIndex >= resultSize) return 1;   /* indicate failure: buffer too small */
		result[resultIndex] = 0;
   //return 0;   /* indicate success */

	*out = ft_strdup("abcd");

	ft_putendl("encode...");
	ft_putendl(result);
	ft_putendl(string);
	return (TRUE);
}
