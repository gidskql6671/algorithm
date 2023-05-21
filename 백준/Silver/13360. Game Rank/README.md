# [Silver III] Game Rank - 13360 

[문제 링크](https://www.acmicpc.net/problem/13360) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 문제 설명

<p>The gaming company Sandstorm is developing an online two player game. You have been asked to implement the ranking system. All players have a rank determining their playing strength which gets updated after every game played. There are 25 regular ranks, and an extra rank, “Legend”, above that. The ranks are numbered in decreasing order, 25 being the lowest rank, 1 the second highest rank, and Legend the highest rank.</p>

<p>Each rank has a certain number of “stars” that one needs to gain before advancing to the next rank. If a player wins a game, she gains a star. If before the game the player was on rank 6-25, and this was the third or more consecutive win, she gains an additional bonus star for that win. When she has all the stars for her rank (see list below) and gains another star, she will instead gain one rank and have one star on the new rank.</p>

<p>For instance, if before a winning game the player had all the stars on her current rank, she will after the game have gained one rank and have 1 or 2 stars (depending on whether she got a bonus star) on the new rank. If on the other hand she had all stars except one on a rank, and won a game that also gave her a bonus star, she would gain one rank and have 1 star on the new rank.</p>

<p>If a player on rank 1-20 loses a game, she loses a star. If a player has zero stars on a rank and loses a star, she will lose a rank and have all stars minus one on the rank below. However, one can never drop below rank 20 (losing a game at rank 20 with no stars will have no effect).</p>

<p>If a player reaches the Legend rank, she will stay legend no matter how many losses she incurs afterwards.</p>

<p>The number of stars on each rank are as follows:</p>

<ul>
	<li>Rank 25-21: 2 stars</li>
	<li>Rank 20-16: 3 stars</li>
	<li>Rank 15-11: 4 stars</li>
	<li>Rank 10-1: 5 stars</li>
</ul>

<p>A player starts at rank 25 with no stars. Given the match history of a player, what is her rank at the end of the sequence of matches?</p>

### 입력 

 <p>The input consists of a single line describing the sequence of matches. Each character corresponds to one game; ‘W’ represents a win and ‘L’ a loss. The length of the line is between 1 and 10 000 characters (inclusive).</p>

### 출력 

 <p>Output a single line containing a rank after having played the given sequence of games; either an integer between 1 and 25 or “Legend”.</p>

