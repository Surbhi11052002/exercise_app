export const exerciseOptions = {
  method: "GET",
  headers: {
    "X-RapidAPI-Key": "a854211270msh5b7e90cfec4bca0p199a03jsndde4741fe441",
    "X-RapidAPI-Host": "exercisedb.p.rapidapi.com",
  },
};
//f81d5c7777msh2d926f7bd8e2c22p1af665jsn76a239cf9aaa;
export const youtubeOptions = {
  method: "GET",
  headers: {
    "X-RapidAPI-Key": "a854211270msh5b7e90cfec4bca0p199a03jsndde4741fe441",
    "X-RapidAPI-Host": "youtube-search-and-download.p.rapidapi.com",
  },
};
//01e85410c6msh69aa82e661c9cd3p1cae5cjsn334b9f0a7121
export const fetchData = async (url, options) => {
  const response = await fetch(url, options);
  const data = await response.json();
  //console.log(data);
  return data;
};
