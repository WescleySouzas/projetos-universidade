// Film Page - Modal de Avaliação
document.addEventListener('DOMContentLoaded', function() {
    const modal = document.getElementById('modal-avaliar-filme');
    const btnNovaAvaliacao = document.getElementById('nova-avaliacao-btn');
    const btnQueroVer = document.getElementById('quero-ver-btn');
    const spanClose = document.querySelector('#modal-avaliar-filme .close');
    const btnCancelar = document.getElementById('cancelar-avaliacao-btn');
    const form = document.getElementById('form-avaliar-filme');
    const stars = document.querySelectorAll('#modal-avaliar-filme .star');
    const ratingValue = document.getElementById('rating-value-filme');

    // Verificar se a música já está na lista de desejos
    verificarStatusQueroVer();

    // Abrir modal
    if (btnNovaAvaliacao) {
        btnNovaAvaliacao.onclick = () => modal.style.display = 'block';
    }
    
    // Botão Quero Ouvir
    if (btnQueroVer) {
        btnQueroVer.onclick = toggleQueroVer;
    }
    
    // Fechar modal
    spanClose.onclick = fecharModal;
    btnCancelar.onclick = fecharModal;
    window.onclick = (e) => { if (e.target == modal) fecharModal(); }
    
    // Sistema de estrelas
    stars.forEach(star => {
        star.onclick = () => {
            const rating = star.getAttribute('data-rating');
            ratingValue.value = rating;
            stars.forEach((s, i) => {
                s.classList.toggle('selected', i < rating);
            });
        };
        
        star.onmouseover = () => {
            const rating = star.getAttribute('data-rating');
            stars.forEach((s, i) => {
                s.classList.toggle('hover', i < rating);
            });
        };
        
        star.onmouseout = () => stars.forEach(s => s.classList.remove('hover'));
    });
    
    // Submit do formulário
    form.onsubmit = (e) => {
        e.preventDefault();
        const rating = ratingValue.value;
        const comentario = document.getElementById('comentario-filme').value.trim();

        if (rating == 0) {
            alert('Por favor, selecione uma avaliação!');
            return;
        }

        if (!comentario) {
            alert('Por favor, escreva um comentário!');
            return;
        }

        criarAvaliacao(rating, comentario);
        
        // Adicionar a avaliação ao sistema dinâmico
        if (typeof adicionarNovaAvaliacao === 'function') {
            adicionarNovaAvaliacao(rating, comentario);
        }
        
        fecharModal();
    };

    function fecharModal() {
        modal.style.display = 'none';
        form.reset();
        ratingValue.value = '0';
        stars.forEach(star => star.classList.remove('selected'));
    }

    function criarAvaliacao(rating, comentario) {
        // Criar as estrelas para exibição
        let estrelas = '';
        for (let i = 1; i <= 5; i++) {
            if (i <= rating) {
                estrelas += '<i class="fa-solid fa-star" style="color: var(--amarelo-star);"></i>';
            } else {
                estrelas += '<i class="fa-regular fa-star" style="color: #ddd;"></i>';
            }
        }

        // Criar novo comentário
        const novoComentario = document.createElement('div');
        novoComentario.className = 'comentario-card';
        novoComentario.innerHTML = `
            <img src="fotos-filmes/ney.jpg" alt="Foto do usuário">
            <div class="comentario-conteudo">
                <div class="comentario-usuario">neymar.realoficial123<i class="fa-solid fa-circle-check" style="color: var(--azul-verificado);"></i></div>
                <div class="comentario-texto">${comentario}</div>
                <div class="comentario-reacoes">
                    <i class="fa-solid fa-thumbs-up"></i> 0
                    <i class="fa-solid fa-thumbs-down"></i> 0
                    <span class="comentario-avaliacao">
                        ${estrelas}
                    </span>
                </div>
            </div>
        `;

        // Adicionar o novo comentário no topo da lista
        const comentariosLista = document.querySelector('.comentarios-lista');
        comentariosLista.insertBefore(novoComentario, comentariosLista.firstChild);

        // Animação suave
        novoComentario.style.opacity = '0';
        novoComentario.style.transform = 'translateY(-20px)';
        setTimeout(() => {
            novoComentario.style.transition = 'all 0.3s ease';
            novoComentario.style.opacity = '1';
            novoComentario.style.transform = 'translateY(0)';
        }, 10);
        
        alert('Avaliação publicada com sucesso!');
    }

    function verificarStatusQueroVer() {
        const queroVer = JSON.parse(localStorage.getItem('queroVer') || '[]');
        const musicaAtual = {
            titulo: 'DAMN. - Kendrick Lamar',
            tipo: 'musica'
        };
        
        const jaSalvo = queroVer.some(item => item.titulo === musicaAtual.titulo);
        const btnQueroVer = document.getElementById('quero-ver-btn');
        
        if (jaSalvo && btnQueroVer) {
            btnQueroVer.innerHTML = '<i class="fa-solid fa-check"></i><span>Já na Lista</span>';
            btnQueroVer.style.background = '#4caf50';
        }
    }

    function toggleQueroVer() {
        const queroVer = JSON.parse(localStorage.getItem('queroVer') || '[]');
        const musicaAtual = {
            titulo: 'DAMN. - Kendrick Lamar',
            artista: 'Kendrick Lamar',
            ano: '2017',
            genero: 'Hip-Hop, Rap',
            imagem: 'fotos-musica/kendrick.jpeg',
            tipo: 'musica',
            estrelas: 5 // Valor padrão baseado na avaliação mostrada
        };
        
        const btnQueroVer = document.getElementById('quero-ver-btn');
        const index = queroVer.findIndex(item => item.titulo === musicaAtual.titulo);
        
        if (index > -1) {
            // Remover da lista
            queroVer.splice(index, 1);
            btnQueroVer.innerHTML = '<i class="fa-solid fa-heart"></i><span>Quero Ouvir</span>';
            btnQueroVer.style.background = '#e53935';
            alert('Removido da sua lista!');
        } else {
            // Adicionar à lista
            queroVer.push(musicaAtual);
            btnQueroVer.innerHTML = '<i class="fa-solid fa-check"></i><span>Já na Lista</span>';
            btnQueroVer.style.background = '#4caf50';
            alert('Adicionado à sua lista de "Quero Ouvir"!');
        }
        
        localStorage.setItem('queroVer', JSON.stringify(queroVer));
    }
});
