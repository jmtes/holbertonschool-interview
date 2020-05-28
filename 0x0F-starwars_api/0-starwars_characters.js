#!/usr/bin/node
const request = require('request');

function queryEndpoint (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (err, res, body) {
      if (!err && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(err);
      }
    });
  });
}

async function getCharNames (charURIs) {
  const charNames = [];

  for (let i = 0; i < charURIs.length; i++) {
    let charData = await queryEndpoint(charURIs[i]);
    charData = await JSON.parse(charData);

    charNames.push(charData.name);
  }

  return charNames;
}

async function getFilmChars (filmID) {
  let filmData = await queryEndpoint(`https://swapi.dev/api/films/${filmID}`);
  filmData = await JSON.parse(filmData);

  const chars = await getCharNames(filmData.characters);
  chars.forEach(char => {
    console.log(char);
  });
}

getFilmChars(process.argv[2]);
