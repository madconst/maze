# The Maze #

This is a simple maze generator that uses randomized depth-first search algorithm. The result is visualized in two ways:

* pseudographics, which can be shown right in the console (utf8)
* scalable vector graphics (svg), which can be opened by any up-to-date Web browser

## Build ##

```
git clone https://github.com/madconst/maze.git
mkdir build && cd $_
cmake ..
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
(https://github.com/madconst/maze_example.png)
