import axios from 'axios';
import React, { useState } from 'react'
import { Link } from 'react-router-dom';

type Props = {}

export default function Register({ }: Props) {

    const [name, setName] = useState('');
    const [surname, setSurname] = useState('');
    const [patron, setPatron] = useState('');
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const handle = async (e: React.FormEvent<HTMLFormElement>) => {
        e.preventDefault();

        const data = {
            name: name,
            surname: surname,
            patron: patron,
            email: email,
            password: password
        }

        await axios.post('/api/register', data)

            .then(response => {
                window.localStorage.setItem('authToken', 'true');
                window.localStorage.setItem('userId', JSON.stringify(response.data.id));
                window.dispatchEvent(new Event('storage'));
                window.location.href = '/home';
            })
    }

    return (
        <>

            <div className='min-h-screen flex justify-center items-center '>
                <div className="absolute w-60 h-60 rounded-xl bg-orange-300 -top-5 -left-16 z-0 transform rotate-45 hidden md:block">
                </div>

                <form className='alignt-center bg-white shadow-md rounded-lg z-20 p-12' onSubmit={handle}>
                    <div>
                        <h1 className="text-3xl font-bold text-center mb-4">Регистрация</h1>
                        <p className="text-center text-sm mb-8 font-semibold text-gray-700">Заполните данные ниже, чтобы создать аккаунт</p>
                    </div>
                    <div className='mb-4'>

                        <label className="block mb-2" htmlFor="name">Имя</label>
                        <input type="text"
                            className='shadow appearance-none border rounded w-full py-2 px-3 mb-4'
                            placeholder='Введите имя'
                            value={name}
                            onChange={(e) => setName(e.target.value)}
                        />

                        <label className="block mb-2" htmlFor="surname">Фамилия</label>
                        <input type="text"
                            className='shadow appearance-none border rounded w-full py-2 px-3 mb-4'
                            placeholder='Введите фамилию'
                            value={surname}
                            onChange={(e) => setSurname(e.target.value)}
                        />

                        <label className="block mb-2" htmlFor="patron">Отчество</label>
                        <input type="text"
                            className='shadow appearance-none border rounded w-full py-2 px-3 mb-4'
                            placeholder='Введите отчество'
                            value={patron}
                            onChange={(e) => setPatron(e.target.value)}
                        />

                        <label className="block mb-2" htmlFor="Email">Электронная почта</label>
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
                            Зарегистрироваться
                        </button>

                        <Link to="/login" className="flex items-center p-2 space-x-3 rounded-md">Уже есть аккаунт?</Link>

                    </div>

                </form>

            </div>
        </>
    )

}

