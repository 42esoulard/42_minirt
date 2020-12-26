/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:40:56 by esoulard          #+#    #+#             */
/*   Updated: 2020/01/24 14:24:53 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/save_bmp.h"

void	init_fh(unsigned char *fh, int filesize)
{
	fh[0] = 'B';
	fh[1] = 'M';
	fh[2] = 0;
	fh[3] = 0;
	fh[4] = 0;
	fh[5] = 0;
	fh[2] = (unsigned char)(filesize);
	fh[3] = (unsigned char)(filesize >> 8);
	fh[4] = (unsigned char)(filesize >> 16);
	fh[5] = (unsigned char)(filesize >> 24);
	fh[6] = 0;
	fh[7] = 0;
	fh[8] = 0;
	fh[9] = 0;
	fh[10] = 54;
	fh[11] = 0;
	fh[12] = 0;
	fh[13] = 0;
}

void	init_ih(unsigned char *ih)
{
	int i;

	i = 0;
	while (i < 40)
		ih[i++] = 0;
	ih[0] = 40;
	ih[4] = (unsigned char)(g_w);
	ih[5] = (unsigned char)(g_w >> 8);
	ih[6] = (unsigned char)(g_w >> 16);
	ih[7] = (unsigned char)(g_w >> 24);
	ih[8] = (unsigned char)(g_h);
	ih[9] = (unsigned char)(g_h >> 8);
	ih[10] = (unsigned char)(g_h >> 16);
	ih[11] = (unsigned char)(g_w >> 24);
	ih[12] = 1;
	ih[14] = 24;
}

void	init_pad(unsigned char *pad)
{
	pad[0] = 0;
	pad[1] = 0;
	pad[2] = 0;
}

void	write_bmp(int fd, unsigned char *bmppad)
{
	int				i;
	int				j;
	unsigned char	bgr_pixel[g_w * g_h * 3];

	i = -1;
	ft_printf("\n\n\033[1;33m			  		  SAVING IMAGE...\n");
	while (++i < g_w * g_h)
	{
		bgr_pixel[i * 3] = g_data[i].b;
		bgr_pixel[i * 3 + 1] = g_data[i].g;
		bgr_pixel[i * 3 + 2] = g_data[i].r;
	}
	i = -1;
	while (++i < g_h)
	{
		j = -1;
		while (++j < g_w)
		{
			write(fd, &bgr_pixel[3 * ((g_w - i - 1) * g_h + j)], 3);
			write(fd, bmppad, (4 - (g_w * 3) % 4) % 4);
		}
	}
	close(fd);
	ft_printf("\n\033[1;35m				    IMAGE SUCCESSFULLY SAVED!\n\n\n");
	free_all();
}

void	save_bmp(void)
{
	int				filesize;
	unsigned char	bmpfileheader[14];
	unsigned char	bmpinfoheader[40];
	unsigned char	bmppad[3];
	int				fd;

	filesize = 54 + 3 * (g_w * g_h);
	init_fh(bmpfileheader, filesize);
	init_ih(bmpinfoheader);
	init_pad(bmppad);
	if (!(fd = open("minirt_img.bmp", O_CREAT | O_RDWR, 0666)))
		error_msg(11, 0);
	write(fd, bmpfileheader, 14);
	write(fd, bmpinfoheader, 40);
	write_bmp(fd, bmppad);
}
