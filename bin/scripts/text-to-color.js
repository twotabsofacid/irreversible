'use strict';

const fs = require('fs');

class TextToColors {
	constructor() {
		fs.readFile('./bin/data/globalwarming.txt', 'utf8', (err, data) => {
			if (err) throw err;
			let hexString = new Buffer(data).toString('hex');
			let newData = hexString[0];
			let i = 1;
			for (i; i < hexString.length; i++) {
				if (i % 6 == 0) {
					newData += '\n';
				}
				newData += hexString[i];
			}
			fs.writeFile('./bin/data/output.txt', newData, (err) => {
				if (err) throw err;
			});
		});
	}
}

new TextToColors();
