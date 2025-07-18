// MetaCritics - JavaScript
const modal = document.getElementById('modal-nova-publicacao');
const btnNovaPublicacao = document.getElementById('nova-publicacao-btn');
const spanClose = document.getElementsByClassName('close')[0];
const btnCancelar = document.getElementById('cancelar-btn');
const form = document.getElementById('form-nova-publicacao');
const stars = document.querySelectorAll('.star');
const ratingValue = document.getElementById('rating-value');

document.addEventListener('DOMContentLoaded', function() {
    console.log('DOM carregado, iniciando aplicação...');
    
    // Aguardar um pouco para garantir que tudo esteja renderizado
    setTimeout(() => {
        // Carregar publicações salvas
        carregarPublicacoesSalvas();
    }, 100);
    
    // Modal
    if (btnNovaPublicacao) {
        btnNovaPublicacao.onclick = () => modal.style.display = 'block';
    } else {
        console.error('Botão nova publicação não encontrado');
    }
    
    if (spanClose) {
        spanClose.onclick = fecharModal;
    }
    
    if (btnCancelar) {
        btnCancelar.onclick = fecharModal;
    }
    
    window.onclick = (e) => { if (e.target == modal) fecharModal(); }
    
    // Estrelas
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
    
    // Submit
    form.onsubmit = (e) => {
        e.preventDefault();
        const tipo = document.getElementById('tipo-conteudo').value;
        const nome = document.getElementById('nome-conteudo').value.trim();
        const foto = document.getElementById('foto-conteudo').value.trim();
        const rating = ratingValue.value;
        const comentario = document.getElementById('comentario-post').value;

        if (!tipo || !nome || rating == 0) {
            alert('Preencha todos os campos obrigatórios!');
            return;
        }

        criarPublicacao(tipo, nome, foto, rating, comentario);
        fecharModal();
    };
    
    // Adicionar suporte para Enter na busca
    const entradaBusca = document.getElementById('entrada');
    if (entradaBusca) {
        entradaBusca.addEventListener('keypress', function(e) {
            if (e.key === 'Enter') {
                irParaSecao();
            }
        });
        
        // Limpar estilos quando começar a digitar
        entradaBusca.addEventListener('input', function() {
            this.style.background = '';
            this.style.borderColor = '';
        });
    }
});

function fecharModal() {
    modal.style.display = 'none';
    form.reset();
    ratingValue.value = '0';
    stars.forEach(star => star.classList.remove('selected'));
}

function criarPublicacao(tipo, nome, foto, rating, comentario) {
    console.log('Criando nova publicação:', { tipo, nome, foto, rating, comentario });
    
    const icones = { filme: 'fa-film', musica: 'fa-music', jogo: 'fa-gamepad' };
    let estrelas = '';
    for (let i = 1; i <= 5; i++) {
        estrelas += i <= rating ? '<i class="fa-solid fa-star"></i>' : '<i class="fa-regular fa-star"></i>';
    }

    // Se não foi fornecida foto, usar uma padrão
    const imagemSrc = foto || 'fotos-filmes/Meta.png';

    const post = document.createElement('section');
    post.className = 'publicacao';
    post.innerHTML = `
        <div class="usuario">
            <img src="fotos-filmes/ney.jpg" alt="Foto do usuário" height="50" width="50"  >
            <div class="comentario-usuario">neymar.realoficial123<i class="fa-solid fa-circle-check" style="color: var(--azul-verificado);"></i></div>
        </div>
        <div class="avaliaçao">
            ${estrelas}
            <span>${comentario || 'Nova publicação!'}</span>
        </div>
        <div class="foto">
            <img src="${imagemSrc}" alt="${nome}" width="300" height="200">
            <span>${nome} <i class="fa-solid ${icones[tipo]}"></i></span>
        </div>
        <div class="reacoes"> 
            <span class="like-btn" onclick="curtir(this)"><i class="fa-solid fa-thumbs-up"></i>0</span>
            <span><i class="fa-solid fa-comments"></i>0</span>
        </div>
    `;

    const menuPrincipal = document.querySelector('.Menu-Principal');
    const primeira = menuPrincipal.querySelector('.publicacao, .publicaçao');
    menuPrincipal.insertBefore(post, primeira);

    // Salvar no localStorage
    const novoPost = {
        tipo: tipo,
        nome: nome,
        imagem: imagemSrc,
        texto: comentario,
        rating: rating,
        estrelas: estrelas,
        timestamp: new Date().toISOString()
    };

    console.log('Salvando no localStorage:', novoPost);
    
    const postagens = JSON.parse(localStorage.getItem("postagens")) || [];
    postagens.unshift(novoPost); // unshift para adicionar no início
    localStorage.setItem("postagens", JSON.stringify(postagens));
    
    console.log('Total de postagens salvas:', postagens.length);

    // Animação
    post.style.opacity = '0';
    post.style.transform = 'translateY(-20px)';
    setTimeout(() => {
        post.style.transition = 'all 0.3s ease';
        post.style.opacity = '1';
        post.style.transform = 'translateY(0)';
    }, 10);
}

function carregarPublicacoesSalvas() {
    console.log('Tentando carregar publicações salvas...');
    
    const postagens = JSON.parse(localStorage.getItem("postagens")) || [];
    console.log('Publicações encontradas:', postagens);
    
    const menuPrincipal = document.querySelector('.Menu-Principal');
    console.log('Menu principal encontrado:', menuPrincipal);
    
    if (!menuPrincipal) {
        console.error('Menu principal não encontrado!');
        return;
    }
    
    if (postagens.length === 0) {
        console.log('Nenhuma publicação salva encontrada.');
        return;
    }
    
    // Carregar cada publicação salva
    postagens.forEach((postagem, index) => {
        console.log(`Carregando publicação ${index + 1}:`, postagem);
        
        const icones = { filme: 'fa-film', musica: 'fa-music', jogo: 'fa-gamepad' };
        
        const post = document.createElement('section');
        post.className = 'publicacao';
        post.innerHTML = `
            <div class="usuario">
                <img src="fotos-filmes/ney.jpg" alt="Foto do usuário" height="50" width="50">
                <div class="comentario-usuario">neymar.realoficial123<i class="fa-solid fa-circle-check" style="color: var(--azul-verificado);"></i></div>
            </div>
            <div class="avaliaçao">
                ${postagem.estrelas || ''}
                <span>${postagem.texto || 'Publicação salva'}</span>
            </div>
            <div class="foto">
                <img src="${postagem.imagem || 'fotos-filmes/Meta.png'}" alt="${postagem.nome || 'Sem título'}" width="300" height="200">
                <span>${postagem.nome || 'Sem título'} <i class="fa-solid ${icones[postagem.tipo] || 'fa-star'}"></i></span>
            </div>
            <div class="reacoes"> 
                <span class="like-btn" onclick="curtir(this)"><i class="fa-solid fa-thumbs-up"></i>0</span>
                <span><i class="fa-solid fa-comments"></i>0</span>
            </div>
        `;
        
        // Adicionar no início do menu principal (antes das outras publicações)
        const primeiraPublicacao = menuPrincipal.querySelector('.publicacao, .publicaçao');
        if (primeiraPublicacao) {
            menuPrincipal.insertBefore(post, primeiraPublicacao);
        } else {
            menuPrincipal.appendChild(post);
        }
        
        console.log(`Publicação ${index + 1} adicionada ao DOM`);
    });
    
    console.log('Todas as publicações foram carregadas!');
}

// Função para debug - pode ser chamada no console do navegador
function debugLocalStorage() {
    const postagens = JSON.parse(localStorage.getItem("postagens")) || [];
    console.log('=== DEBUG LOCALSTORAGE ===');
    console.log('Total de postagens:', postagens.length);
    console.log('Postagens:', postagens);
    console.log('========================');
    return postagens;
}

// Função para limpar localStorage - pode ser chamada no console do navegador
function limparLocalStorage() {
    localStorage.removeItem("postagens");
    console.log('localStorage limpo!');
    location.reload();
}

function irParaSecao() {
    const entrada = document.getElementById('entrada');
    const valor = entrada.value.trim();
    
    if (!valor) {
        entrada.focus();
        entrada.style.borderColor = '#e53935';
        entrada.placeholder = 'Digite algo primeiro!';
        setTimeout(() => {
            entrada.style.borderColor = '';
            entrada.placeholder = 'Digite #nomedapagina';
        }, 2000);
        return;
    }
    
    if (valor.startsWith('#')) {
        const secao = valor.slice(1).toLowerCase();
        // Lista de páginas válidas
        const paginasValidas = ['film', 'game', 'bibliotecafilmes', 'bibliotecajogos', 'bibliotecamusica', 'perfilmeta', 'loginmeta'];
        
        if (paginasValidas.includes(secao)) {
            // Animação de sucesso
            entrada.style.background = 'rgba(76, 175, 80, 0.3)';
            setTimeout(() => {
                window.location.href = `${secao}.html`;
            }, 300);
        } else {
            entrada.style.background = 'rgba(244, 67, 54, 0.3)';
            entrada.value = '';
            entrada.placeholder = 'Página não encontrada!';
            setTimeout(() => {
                entrada.style.background = '';
                entrada.placeholder = 'Digite #nomedapagina';
            }, 2000);
        }
    } else {
        entrada.style.background = 'rgba(255, 152, 0, 0.3)';
        entrada.focus();
        entrada.placeholder = 'Use # antes do nome!';
        setTimeout(() => {
            entrada.style.background = '';
            entrada.placeholder = 'Digite #nomedapagina';
        }, 2000);
    }
}

