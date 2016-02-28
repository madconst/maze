# The Maze #

This is a simple maze generator employing **randomized depth-first search** algorithm. The result is visualized in two ways:

* pseudographics, which works right in linux console (utf8)
* scalable vector graphics (svg), which can be opened by any up-to-date Web browser

The maze is stored in an efficient data structure which requires only 3 bits per cell (2 bits for walls and 1 bit for status: visited/pristine).

## Build ##

```
git clone https://github.com/madconst/maze.git
cd maze
mkdir build && cd $_
cmake ../src
make
```

## Run ##

In Linux:

```
$ ./generate_text_maze
╥╔═══╗╔╡╔╦════╗╔══╦╗╞╦═╗╞╦╗╞╦══╗╞╗╔╦╗╔═╗
║║╔═╗╚╝╔╝╚╗╞╗╔╝║╞╗║╚═╝╔╩═╝╚═╝╥╔╩═╝║║║╚╗║
║║║╥║╔═╩═╡║╔╣╚╗╚═╣╚═╗╥║╔═══╗╞╩╬╡╔═╝║║╔╝║
║╚╩╝╠╝╞╗╔═╝║╚╡╚═╗╨╔═╣╚╝╚═╗╔╝╔╗╨╔╝╔═╝║╚╗╨
╚╗╔╗╚╦═╝║╔═╩═══╗║╔╝╞╝╔╦╡╔╝╚═╝╚╗║╔╝╞═╩╗╚╗
╥╚╝╚╗╨╔═╝╚═╗╔═╗╚╝╚══╗║╚═╝╔╗╔═╗╠╝║╔═╗╞╩═╣
╠═╗╥╚╗║╔═╦╡╚╝╔╝╔╦══╗║║╔═╗║╚╝╔╝║╥╚╝╔╝╔╗╞╝
║╔╝╠╡║║║╞╝╔══╝╥║║╞═╬╝║╚╡║║╔╗║╔╝╠╗╥║╔╝╚═╗
║╚═╣╔╝║╠═╗║╞══╣║║╔╗╨╔╩══╣║╨║║╚═╝╚╣╚╝╔═╗║
╠╗╔╝╚═╝╚╗║╚══╗╚╝╚╝╠═╝╔╗╞╝╚╗║╚══╗╞╩╗╔╝╞╩╝
║║║╔══╦╗╨╚╦╗╥╚═══╗║╞╗║║╔╗╔╝╠══╡╚╗╥║╚═══╗
║║╨║╔═╝╚═╦╝╚╩═╗╔═╝║╔╝║║║╚╝╔╩═══╗║║╠╡╔══╣
║╚═╝╚╗╞╗╔╝╔══╗╨╚═╗╚╝╔╝╚╝╔╗║╔═╦╗╚╝╚╝╔╝╥╔╝
╚══╗╥╚╗╚╩╡║╥╔╝╔╦╡╚═╗╚═╗╔╝╚╝╨╔╝╚╗╔══╝╥╠╝╥
╞══╩╩╡╚═══╩╝╚═╝╚═══╩══╝╚════╝╞═╩╝╞══╩╩═╝
```

```
$ ./generate_svg_maze > maze.html
```

After that open the file with a web browser. It should look like this:

![Maze Example]
(https://raw.githubusercontent.com/madconst/maze/master/maze_example.png)
