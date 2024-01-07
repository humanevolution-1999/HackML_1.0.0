document.addEventListener('DOMContentLoaded', function() {
    // Find the target <div> by its id
    var container = document.getElementById('home_page_content')


    var speed = 50; // Speed of typing in milliseconds
    var textarray = ['Real time', 'Interpreter', 'of Hack', 'Machine Language']
    //var textContent = 'Real time interpreter of Hack Assembly Language.'

    function typeText(index) {
        if (index < textContent.length) {

            
            //console.log(i,index,textContent);
            // Create a new <p> element
            var paragraph = document.createElement('p');

            // Add content to the <p> element
            paragraph.textContent = textContent.slice(0, index + 1);

            // Add the special class to the <p> element
            paragraph.classList.add('home_page_content_body');

            // Replace the last added paragraph and add the latest one again
            var lastChild = container.lastChild;
            //console.log('last',lastChild.textContent);
            if (lastChild) {
                container.removeChild(lastChild);
            }
            var lastChild = container.lastChild;
            //console.log('here',lastChild.textContent);
            container.appendChild(paragraph);
            

            // Schedule the next character to be typed after the specified speed
            setTimeout(function() {
                typeText(index + 1);
            }, speed);
        }
    }

    for (let i=0;i<textarray.length; i++)
    {
        var temp_para = document.createElement('p');
        temp_para.textContent='check';
        container.append(temp_para);
        var textContent = textarray[i];
        console.log(textContent.length);
        
        //console.log('first reached here',i);
        // Start typing from the first character
        typeText(0);
   }
    

    /*// Create a new <p> element
    var paragraph = document.createElement('p');

    // Add content to the <p> element
    paragraph.textContent = 'Real time interpreter of Hack Assembly Language.';
    
    // Add the special class to the <p> element
    paragraph.classList.add('home_page_content_body');

    // Append the <p> element to the target <div>
    targetDiv.appendChild(paragraph);*/
});

//console.log(document.getElementsByClassName('home_page_content'));