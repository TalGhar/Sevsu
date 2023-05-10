pragma solidity >=0.4.2;

contract Election {
    // Модель данных кандидата
    struct Candidate {
        uint id;
        string name;
        uint voteCount;
    }

    // Хранилище конадидатов
    // Получаем отсюда же, без геттеров
    mapping(uint => Candidate) public candidates;
    
    // Store accounts that have voted
    mapping(address => bool) public voters;

    // Счетчик кандидатов
    uint public candidatesCount;

    constructor() public {
        addCandidate("Candidate 1");
        addCandidate("Candidate 2");
    }

    function addCandidate (string memory _name ) private {
        candidatesCount ++;
        candidates[candidatesCount] = Candidate(candidatesCount, _name, 0);
    }

    function vote (uint _candidateId) public {
        require(!voters[msg.sender]);
        require(_candidateId > 0 && _candidateId <= candidatesCount);
        voters[msg.sender] = true;
        candidates[_candidateId].voteCount ++;
        // После завершения обработки транзакции – запустим событие.
        emit votedEvent(_candidateId);
    }

    event votedEvent (
        uint indexed _candidateId
    );

}