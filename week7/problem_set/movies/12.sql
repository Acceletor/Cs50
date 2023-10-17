-- SELECT movies.title
-- FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON stars.person_id = people.id
-- WHERE people.name LIKE 'Bradley Cooper'
-- INTERSECT
-- SELECT movies.title
-- FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON stars.person_id = people.id
-- WHERE people.name LIKE 'Jennifer Lawrence';

-- SELECT m.title
-- FROM movies m
-- JOIN stars s1 ON m.id = s1.movie_id
-- JOIN people p1 ON s1.person_id = p1.id
-- JOIN stars s2 ON m.id = s2.movie_id
-- JOIN people p2 ON s2.person_id = p2.id
-- WHERE p1.name = 'Bradley Cooper'
--   AND p2.name = 'Jennifer Lawrence';

SELECT m.title FROM movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p ON s.person_id = p.id
WHERE p.name IN ('Bradley Cooper','Jennifer Lawrence')
GROUP BY m.title
HAVING COUNT(DISTINCT p.name) = 2;
