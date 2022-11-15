# lem-in
Ant farm manager
 
 <img width="883" alt="image" src="https://user-images.githubusercontent.com/58331418/201905380-36db415c-bf8f-4558-b3a9-339fb1f68afa.png">

Lem-in is the second to last project in the Algorithm branch at Hive Helsinki. It is a project done in a group of 2 and my partner for this project was another student of Hive, Atte Köykkä.


**Here is a visual representation of how our algorithm works!**

![lemin](https://user-images.githubusercontent.com/58331418/201911516-7a0d353f-b9a6-457e-a3a8-19f7343f3284.gif)


**lem-in**

Lem-in is a graph traversal project where you get a map as an input, and you have to find the best set of paths to move any given ammount of ants from start to end. The map will have nodes and links and only one ant can be in a node at a time. All nodes have a different ammount of links.


**How we approached the problem**

We did quite a bit of research before starting coding. We ended up using a combination **breadth-first search**-algorithm and a modified version of **Dijkstra's algorithm** to find our set of paths.


**What I learned from this project**

Since this project was done in a team, I obviously picked up quite a few things about how to work (and how not to work) in a team. In addition to that this was the first time we got to actually find a pre-existing algorithm and implement it in our own programs. Previously we got by with just coming up with sinple algorithms on our own but here we had to *(well didn't have to but it was smart)* use a pre-existing algorithm to accomplish our goals. 

There was also quite a bit of complex parsing in this project, since we received the maps as files and had to read, validate and transfer the data to a form we could use with our program. We used a hashmap approach to this which was also a new, but overall very useful concept to learn.
