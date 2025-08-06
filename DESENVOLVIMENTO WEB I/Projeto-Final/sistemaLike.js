// Sistema de Like Super Simples
function curtir(elemento) {
    // Pegar o número atual
    let numero = parseInt(elemento.textContent.match(/\d+/)[0]);
    
    // Se já curtiu, descurtir. Se não curtiu, curtir.
    if (elemento.style.color === 'rgb(25, 118, 210)' || elemento.style.color === '#1976d2') {
        // Descurtir
        numero = numero - 1;
        elemento.innerHTML = '<i class="fa-solid fa-thumbs-up"></i>' + numero;
        elemento.style.color = '';
    } else {
        // Curtir
        numero = numero + 1;
        elemento.innerHTML = '<i class="fa-solid fa-thumbs-up"></i>' + numero;
        elemento.style.color = '#1976d2';
    }
}

// Função para adicionar sistema de like a novos posts
function adicionarLikeNovoPost(elemento) {
    const botaoLike = elemento.querySelector('.like-btn');
    if (botaoLike) {
        botaoLike.addEventListener('click', function() {
            toggleLike(botaoLike);
        });
    }
}
