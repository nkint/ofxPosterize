
$(document).ready(function() {
	var currentPalette = palette1;
	console.log(currentPalette);
	var colorContainer = $("#resultColors");
	console.log(colorContainer);

	// add palette block
	for(i in currentPalette) {
		var color = currentPalette[i];
		col = chroma.rgb(color.r, color.g, color.b);
		
		var container = 
		$('<div/>', {
		    class: 'colorResult-container',
		})
		var top = 
		$('<div/>', {
		    class: 'colorResult-top',
		    style: 'background-color: rgb('+color.r+','+color.g+','+color.b+');',
		}).appendTo(container);
		var bottom =
		$('<div/>', {
			class: 'colorResult-bottom'
		}).appendTo(container);
		var table_string = " \
			<table> \
				<tbody> \
                    <tr> \
                        <td class='colorResult-value colorResult-hex'>"+col.hex()+"</td> \
                        <td class='colorResult-value colorResult-rgb'>"+col.rgb+"</td> \
                        <td class='colorResult-filler'></td> \
                    </tr> \
                    <tr> \
                        <td class='colorResult-label'>HEX</td> \
                        <td class='colorResult-label'>RGB</td> \
                        <td></td> \
                    </tr> \
                </tbody> \
            </table>";

		bottom.append(table_string);
		container.appendTo(colorContainer);
	}

	// add codes
	var pre_hexjson_string = '<pre>[';
	var pre_rgbjson_string = '<pre>[';
	var pre_rgblist_string = '<pre>';
	var pre_hexlist_string = '<pre>';
	for(i in currentPalette) {
		var color = currentPalette[i];
		col = chroma.rgb(color.r, color.g, color.b);

		pre_hexjson_string += '"'+ col.hex() +'",<br>';
		pre_rgbjson_string += '['+ col.rgb   +'],<br>';

		pre_rgblist_string += 'rgb('+col.rgb+')<br>'
		pre_hexlist_string += col.hex()+'<br>';
	}
	pre_hexjson_string = pre_hexjson_string.substr(0, pre_hexjson_string.length-5);
	pre_hexjson_string += ']</pre>';
	var container_js = $('#resultColors_hexjson').append(pre_hexjson_string);

	pre_rgbjson_string = pre_rgbjson_string.substr(0, pre_rgbjson_string.length-5);
	pre_rgbjson_string += ']</pre>';
	container_js = $('#resultColors_rgbjson').append(pre_rgbjson_string);

	pre_rgblist_string = pre_rgblist_string.substr(0, pre_rgblist_string.length-4);
	pre_rgblist_string += '</pre>';
	container_js = $('#resultColors_rgblist').append(pre_rgblist_string);

	pre_hexlist_string = pre_hexlist_string.substr(0, pre_hexlist_string.length-4);
	pre_hexlist_string += '</pre>';
	pre_hexlist_string = $('#resultColors_hexlist').append(pre_hexlist_string);
	//resultColors_hexlist



});