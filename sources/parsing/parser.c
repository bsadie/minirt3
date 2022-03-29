/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:18:06 by bsadie            #+#    #+#             */
/*   Updated: 2022/03/29 19:25:38 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parser.h"

void	init_scene(t_scene *scene)
{
	scene->objects = NULL;
	scene->height = IMG_HEIGHT;
	scene->width = IMG_WIDTH;
	scene->camera.fov = -1;
	scene->ambient_color.red = -1;
	scene->light.intensity = -1;
}

void	parse_line(t_scene *scene, char **splitted_line)
{
	if (array_len(splitted_line) == 0)
		return ;
	else if (array_len(splitted_line) < 2)
		put_error_exit("Input file: wrong line");
	if (!ft_strncmp(splitted_line[0], "A", 1))
		parse_ambient(scene, splitted_line);
	else if (!ft_strncmp(splitted_line[0], "L", 1))
		parse_light(scene, splitted_line);
	else if (!ft_strncmp(splitted_line[0], "C", 1))
		parse_camera(scene, splitted_line);
	else if (!ft_strncmp(splitted_line[0], "sp", 2))
		parse_sphere(scene, splitted_line);
	else if (!ft_strncmp(splitted_line[0], "pl", 2))
		parse_plane(scene, splitted_line);
	else if (!ft_strncmp(splitted_line[0], "cy", 2))
		parse_cylinder(scene, splitted_line);
	else
		put_error_exit("Input file: wrong line");
}

int	gnl_loop(int fd, t_scene *scene)
{
	int		rtn;
	char	*next_line;
	char	**splitted_line;

	rtn = get_next_line(fd, &next_line);
	if (!check_line(next_line))
		put_error_exit("Input file: wrong symbol");
	splitted_line = ft_split(next_line, ' ');
	parse_line(scene, splitted_line);
	free(splitted_line);
	return (rtn);
}

t_scene	*parse_file(char *path)
{
	int		fd;
	int		gnl_status;
	t_scene	*scene;

	fd = open(path, O_RDONLY);
	scene = malloc(sizeof(t_scene));
	check_malloc(scene);
	scene->objects = malloc(sizeof(t_list *));
	check_malloc(scene->objects);
	if (fd == -1)
		return (NULL);
	init_scene(scene);
	gnl_status = 1;
	while (gnl_status > 0)
		gnl_status = gnl_loop(fd, scene);
	gnl_loop(fd, scene);
	close(fd);
	check_scene(scene);
	return (scene);
}
