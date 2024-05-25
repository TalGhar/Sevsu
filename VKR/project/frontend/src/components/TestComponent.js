import React, { useState } from 'react'

import axios from 'axios'

export default function TestComponent() {

    const [test, setTest] = useState([])


    function getTest() {
        axios.get('http://localhost:8080/test')
            .then((response) => onSuccess(response))
            .catch((response) => onError(response))
            .finally(() => console.log('Done'))
    }

    function onSuccess(response) {
        console.log(response);
        setTest(response.data);

    }

    function onError(response) {
        console.log(response);
    }

    return (
        <div>
            TestComponent
            <div>
                {
                    test.map(
                        t => (
                            <a>{t.id}</a>
                        )
                    )
                }
            </div>
            <button className="btn btn-success" onClick={getTest}>Get test</button>
        </div>

    )
}
