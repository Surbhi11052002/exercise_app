export const exerciseOptions = {
  method: "GET",
  headers: {
    "X-RapidAPI-Key": "01e85410c6msh69aa82e661c9cd3p1cae5cjsn334b9f0a7121",
    "X-RapidAPI-Host": "exercisedb.p.rapidapi.com",
  },
};

export const youtubeOptions = {
  method: "GET",
  headers: {
    "X-RapidAPI-Key": "01e85410c6msh69aa82e661c9cd3p1cae5cjsn334b9f0a7121",
    "X-RapidAPI-Host": "youtube-search-and-download.p.rapidapi.com",
  },
};

export const fetchData = async (url, options) => {
  const response = await fetch(url, options);
  const data = await response.json();
  return data;
};
