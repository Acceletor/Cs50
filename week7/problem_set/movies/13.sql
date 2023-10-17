SELECT p1.name
FROM movies
JOIN stars s1 ON movies.id = s1.movie_id
JOIN people p1 ON s1.person_id = p1.id
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name like 'Kevin Bacon'
AND people.birth = 1958 AND p1.name != 'Kevin Bacon';
