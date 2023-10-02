<template>
    <div>
        <h2>Todo List</h2>
        <ul>
            <li v-for="task in tasks" :key="task.label">
                <label>
                    <input type="checkbox" v-model="task.completed" @click="setCompleted(task)">
                    {{ task.label }}
                </label>
            </li>
        </ul>
        <form @submit.prevent="addTask">
            <label>
                New Task:
                <input type="text" v-model="newTaskLabel">
            </label>
            <button type="submit">Add</button>
        </form>
    </div>
</template>

<script>
export default {
    data() {
        return {
            tasks: [

            ],
            newTaskLabel: '',
        };
    },
    methods: {
        addTask() {
            if (this.newTaskLabel.trim() !== '') {
                this.tasks.push({ label: this.newTaskLabel, completed: false });
                this.newTaskLabel = '';
            }
        },
        setCompleted(task) {
            task.completed = !task.completed;
        },
    },
};
</script>