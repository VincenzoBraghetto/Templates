const root = document.documentElement;

function setUserStyles() {
    const primaryColor = document.getElementById("primary-color").value;
    
    root.style.setProperty('--PRIMARY-COLOR', primaryColor);
};
