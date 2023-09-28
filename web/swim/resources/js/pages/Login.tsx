import axios from 'axios';
import { error } from 'console';
import React, { useState } from 'react'
import { Link } from 'react-router-dom';

type Props = {}

export default function Login({ }: Props) {

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const handle = async (e: React.FormEvent<HTMLFormElement>) => {
        e.preventDefault();

        const data = {
            email: email,
            password: password
        }

        await axios.post('/api/login', data)

            .then(response => {

                window.location.href = '/home';
                response.data ? window.localStorage.setItem('authToken', 'true') : console.log('error');
            })
    }

    return (
        <>

            <div className='min-h-screen flex justify-center items-center'>

                <div className="absolute w-60 h-60 rounded-xl bg-orange-300 -top-5 -left-16 z-0 transform rotate-45 hidden md:block">
                </div>

                <form className='align-center bg-white z-20 shadow-md rounded-20 p-12' onSubmit={handle}>
                    <div>
                        <h1 className='text-3xl font-bold text-center mb-4'>Вход</h1>
                        <p className='text-center text-sm mb-8 font-semibold text-gray-700'>Введите данные Вашего аккаунта</p>
                    </div>

                    <div className='mb-4'>

                        <label className="block mb-2" htmlFor="email">Электронная почта</label>
                        <input type="email"
                            className='shadow appearance-none border rounded w-full py-2 px-3 mb-4'
                            placeholder='Введите почту'
                            value={email}
                            onChange={(e) => setEmail(e.target.value)}
                        />

                        <label className="block mb-2" htmlFor="password">Пароль</label>
                        <input type="password"
                            className='shadow appearance-none border rounded w-full py-2 px-3 mb-4'
                            placeholder='Введите пароль'
                            value={password}
                            onChange={(e) => setPassword(e.target.value)}
                        />

                        <button type='submit' className='bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:shadow-outline'>
                            Войти
                        </button>

                        <Link to="/register" className="flex items-center p-2 space-x-3 rounded-md">Ещё нет аккаунта?</Link>

                    </div>

                </form>
            </div>

        </>
    );
}

